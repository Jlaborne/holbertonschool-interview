#include <stdlib.h>
#include <string.h>
#include "substring.h"

/* Compare two C-string pointers for qsort (words are null-terminated). */
static int cmp_words(const void *a, const void *b)
{
    const char *const *pa = (const char *const *)a;
    const char *const *pb = (const char *const *)b;
    return strcmp(*pa, *pb);
}

/* Binary search a L-length substring (not null-terminated) in sorted uniq[].
   Returns index in uniq (0..U-1) or -1 if not found. */
static int find_in_uniq(const char *w, const char **uniq, int U, int L)
{
    int lo = 0, hi = U - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int c = strncmp(w, uniq[mid], (size_t)L);
        if (c == 0)
            return mid;
        if (c < 0)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *indices = NULL;
    int capacity, found = 0;
    size_t s_len;
    int L, U = 0, i, j, k;

    if (n)
        *n = 0;
    if (!s || !words || nb_words <= 0 || !n)
        return NULL;

    L = (int)strlen(words[0]);
    if (L == 0)
        return NULL;

    s_len = strlen(s);
    if ((size_t)(L * nb_words) > s_len)
        return NULL;

    /* Build unique word list and required counts */
    const char **uniq = malloc((size_t)nb_words * sizeof(*uniq));
    int *need = malloc((size_t)nb_words * sizeof(*need));
    if (!uniq || !need)
    {
        free(uniq);
        free(need);
        return NULL;
    }

    for (i = 0; i < nb_words; i++)
    {
        /* Assume all words have same length L as per requirement */
        int found_idx = -1;
        for (j = 0; j < U; j++)
        {
            if (strcmp(words[i], uniq[j]) == 0)
            {
                found_idx = j;
                break;
            }
        }
        if (found_idx == -1)
        {
            uniq[U] = words[i];
            need[U] = 1;
            U++;
        }
        else
        {
            need[found_idx]++;
        }
    }

    /* Sort uniq[] lexicographically for binary search */
    qsort((void *)uniq, (size_t)U, sizeof(*uniq), cmp_words);

    /* Rebuild need[] to match the sorted uniq[] order */
    /* First, count again into a temp array aligned to sorted uniq[] */
    int *need_sorted = calloc((size_t)U, sizeof(*need_sorted));
    if (!need_sorted)
    {
        free(uniq);
        free(need);
        return NULL;
    }
    for (i = 0; i < nb_words; i++)
    {
        int idx = find_in_uniq(words[i], uniq, U, L);
        if (idx != -1)
            need_sorted[idx]++;
    }
    free(need);
    need = need_sorted;

    /* Result capacity: at most s_len indices */
    capacity = (int)s_len;
    indices = malloc((size_t)capacity * sizeof(*indices));
    if (!indices)
    {
        free(uniq);
        free(need);
        return NULL;
    }

    /* Sliding window for each offset modulo L */
    for (i = 0; i < L; i++)
    {
        int left = i;
        int count = 0;
        int *have = calloc((size_t)U, sizeof(*have));
        if (!have)
        {
            free(indices);
            free(uniq);
            free(need);
            return NULL;
        }

        for (j = i; j + L <= (int)s_len; j += L)
        {
            int idx = find_in_uniq(s + j, uniq, U, L);

            if (idx != -1)
            {
                have[idx]++;
                count++;

                /* Shrink from the left if this word is over-used */
                while (have[idx] > need[idx])
                {
                    int idx_left = find_in_uniq(s + left, uniq, U, L);
                    have[idx_left]--;
                    left += L;
                    count--;
                }

                /* If window has exactly nb_words words, record index */
                if (count == nb_words)
                {
                    if (found < capacity)
                        indices[found++] = left;

                    /* Move left by one word to look for next */
                    {
                        int idx_left = find_in_uniq(s + left, uniq, U, L);
                        have[idx_left]--;
                        left += L;
                        count--;
                    }
                }
            }
            else
            {
                /* Reset window after a non-matching chunk */
                memset(have, 0, (size_t)U * sizeof(*have));
                count = 0;
                left = j + L;
            }
        }
        free(have);
    }

    free(uniq);
    free(need);

    if (found == 0)
    {
        free(indices);
        return NULL;
    }

    /* Optionally shrink allocation (not required) */
    /* int *tmp = realloc(indices, (size_t)found * sizeof(*indices));
    if (tmp) indices = tmp; */

    *n = found;
    return indices;
}
