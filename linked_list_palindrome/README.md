# Linked List Palindrome

## Description

This project is part of the Holberton School interview preparation and aims to determine whether a singly linked list is a palindrome.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation is done on `Ubuntu 14.04 LTS`
- Programs and functions are compiled with `gcc 4.8.4` using the following flags:
  ```sh
  gcc -Wall -Werror -Wextra -pedantic
  ```
- Code follows the `Betty` coding style (checked using `betty-style.pl` and `betty-doc.pl`)
- No global variables allowed
- No more than 5 functions per file
- All header files should be include guarded

## Files

### `lists.h`

Contains the structure definition for the linked list and function prototypes:

```c
#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head);
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

#endif /* LISTS_H */
```

### `0-is_palindrome.c`

This file contains the implementation of the function that checks whether a linked list is a palindrome.

### `linked_lists.c`

Contains helper functions to manage the linked list:

- `print_listint` - Prints all elements of a linked list.
- `add_nodeint_end` - Adds a new node at the end of the linked list.
- `free_listint` - Frees a linked list.

### `0-main.c`

Example test file to check if the function works as expected.

## Compilation and Usage

To compile the project, run:

```sh
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

To execute:

```sh
./palindrome
```

## Example Output

```
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

## Author

**Erwan Lebreton** - Student at Holberton School
