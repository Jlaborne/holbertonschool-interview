## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `search.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks

### 1.

Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a [skip list](/rltoken/hx9CJ0x4myPKeqv9Wzdrnw "skip list").

Write a function that searches for a value in a sorted skip list of integers.

- Prototype : `skiplist_t *linear_skip(skiplist_t *list, int value);`
- Where `list` is a pointer to the head of the skip list to search in
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
- And `value` is the value to search for
- You can assume that `list` will be sorted in ascending order
- Your function must return a pointer on the first node where `value` is located
- If `value` is not present in `list` or if `head` is `NULL`, your function must return `NULL`
- Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)

NOTE: [You can find here](/rltoken/zSPM9W2XTy45ZB6QaCv5Jw "You can find here") the functions used in the example. You don’t need to push them, we will compile your file with our own implementation during the correction. BUT, **don’t forget to push** `search.h`

```
alex@~/linear\_skip$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist\_t \*create\_skiplist(int \*array, size\_t size);
void print\_skiplist(const skiplist\_t \*list);
void free\_skiplist(skiplist\_t \*list);

/\*\*
 \* main - Entry point
 \*
 \* Return: Always EXIT\_SUCCESS
 \*/
int main(void)
{
    skiplist\_t \*list, \*res;
    int array\[\] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size\_t size = sizeof(array) / sizeof(array\[0\]);

    list = create\_skiplist(array, size);
    print\_skiplist(list);

    res =  linear\_skip(list, 53);
    printf("Found %d at index: %lu\\n\\n", 53, res->index);
    res =  linear\_skip(list, 2);
    printf("Found %d at index: %lu\\n\\n", 2, res->index);
    res =  linear\_skip(list, 999);
    printf("Found %d at index: %p\\n", 999, (void \*) res);

    free\_skiplist(list);
    return (EXIT\_SUCCESS);
}
alex@~/linear\_skip$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear\_skip.c skiplist/\*.c -lm -o 0-linear\_skip
alex@~/linear\_skip$ ./0-linear\_skip
List :
Index\[0\] = \[0\]
Index\[1\] = \[1\]
Index\[2\] = \[2\]
Index\[3\] = \[3\]
Index\[4\] = \[4\]
Index\[5\] = \[7\]
Index\[6\] = \[12\]
Index\[7\] = \[15\]
Index\[8\] = \[18\]
Index\[9\] = \[19\]
Index\[10\] = \[23\]
Index\[11\] = \[53\]
Index\[12\] = \[61\]
Index\[13\] = \[62\]
Index\[14\] = \[76\]
Index\[15\] = \[99\]

Express lane :
Index\[0\] = \[0\]
Index\[4\] = \[4\]
Index\[8\] = \[18\]
Index\[12\] = \[61\]

Value checked at index \[4\] = \[4\]
Value checked at index \[8\] = \[18\]
Value checked at index \[12\] = \[61\]
Value found between indexes \[8\] and \[12\]
Value checked at index \[8\] = \[18\]
Value checked at index \[9\] = \[19\]
Value checked at index \[10\] = \[23\]
Value checked at index \[11\] = \[53\]
Found 53 at index: 11

Value checked at index \[4\] = \[4\]
Value found between indexes \[0\] and \[4\]
Value checked at index \[0\] = \[0\]
Value checked at index \[1\] = \[1\]
Value checked at index \[2\] = \[2\]
Found 2 at index: 2

Value checked at index \[4\] = \[4\]
Value checked at index \[8\] = \[18\]
Value checked at index \[12\] = \[61\]
Value found between indexes \[12\] and \[15\]
Value checked at index \[12\] = \[61\]
Value checked at index \[13\] = \[62\]
Value checked at index \[14\] = \[76\]
Value checked at index \[15\] = \[99\]
Found 999 at index: (nil)
alex@~/linear\_skip$
```
