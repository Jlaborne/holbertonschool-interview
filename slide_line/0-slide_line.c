#include "slide_line.h"

/**
 * slide_left - Slides and merges to the left
 * @line: The array to operate on
 * @size: Size of the array
 * Return: 1 on success
 */
int slide_left(int *line, size_t size)
{
    size_t i, pos = 0;
    int merged[size];  // Keep track of merged positions
    for (i = 0; i < size; i++)
        merged[i] = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] == 0)
            continue;

        if (pos > 0 && line[pos - 1] == line[i] && merged[pos - 1] == 0)
        {
            line[pos - 1] *= 2;
            line[i] = 0;
            merged[pos - 1] = 1;
        }
        else
        {
            if (i != pos)
            {
                line[pos] = line[i];
                line[i] = 0;
            }
            pos++;
        }
    }
    return 1;
}

/**
 * slide_right - Slides and merges to the right
 * @line: The array to operate on
 * @size: Size of the array
 * Return: 1 on success
 */
int slide_right(int *line, size_t size)
{
    int merged[size];
    size_t i, pos = size - 1;

    for (i = 0; i < size; i++)
        merged[i] = 0;

    for (i = size; i-- > 0;)
    {
        if (line[i] == 0)
            continue;

        if (pos < size - 1 && line[pos + 1] == line[i] && merged[pos + 1] == 0)
        {
            line[pos + 1] *= 2;
            line[i] = 0;
            merged[pos + 1] = 1;
        }
        else
        {
            if (i != pos)
            {
                line[pos] = line[i];
                line[i] = 0;
            }
            if (pos > 0)
                pos--;
        }
    }
    return 1;
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Number of elements in line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    if (direction == SLIDE_LEFT)
        return slide_left(line, size);
    else
        return slide_right(line, size);
}