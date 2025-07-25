## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks

### 40.

Write a function that extracts the root node of a Max Binary Heap:

- Prototype: `int heap_extract(heap_t **root);`
- `root` is a double pointer to the root node of the heap
- Your function must return the value stored in the root node
- The root node must be freed and replace with the last `level-order` node of the heap
- Once replaced, the heap must be rebuilt if necessary
- If your function fails, return `0`

Note: In order for the main file to compile, you are provided with [this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/466/libheap.a "this static library"). This library won’t be used during correction, its only purpose is for testing.

```
alex@/tmp/binary\_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "binary\_trees.h"

/\*
 \* The following are helpers functions needed in this main file
 \* You don't need them in your \`heap\_extract function\`.
 \*/
heap\_t \*\_array\_to\_heap(int \*array, size\_t size);
void binary\_tree\_print(const binary\_tree\_t \*tree);
void \_binary\_tree\_delete(binary\_tree\_t \*tree);

/\*\*
 \* main - Entry point
 \*
 \* Return: 0 on success, error code on failure
 \*/
int main(void)
{
    heap\_t \*tree;
    int array\[\] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size\_t n = sizeof(array) / sizeof(array\[0\]);
    int extract;

    tree = \_array\_to\_heap(array, n);
    if (!tree)
        return (1);
    binary\_tree\_print(tree);

    extract = heap\_extract(&tree);
    printf("Extracted: %d\\n", extract);
    binary\_tree\_print(tree);

    extract = heap\_extract(&tree);
    printf("Extracted: %d\\n", extract);
    binary\_tree\_print(tree);

    extract = heap\_extract(&tree);
    printf("Extracted: %d\\n", extract);
    binary\_tree\_print(tree);
    \_binary\_tree\_delete(tree);
    return (0);
}
alex@/tmp/binary\_trees$ gcc -Wall -Wextra -Werror -pedantic -o 0-heap\_extract 0-main.c 0-heap\_extract.c binary\_tree\_print.c -L. -lheap
alex@/tmp/binary\_trees$ valgrind ./0-heap\_extract
==29133== Memcheck, a memory error detector
==29133== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==29133== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==29133== Command: ./0-heap\_extract
==29133==
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)
Extracted: 98
                 .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
Extracted: 95
                 .-----------------(091)-----------------.
       .-------(084)-------.                   .-------(087)-------.
  .--(047)--.         .--(079)--.         .--(068)--.         .--(062)
(032)     (034)     (002)     (020)     (022)     (021)     (001)
Extracted: 91
                 .-----------------(087)-----------------.
       .-------(084)-------.                   .-------(068)--.
  .--(047)--.         .--(079)--.         .--(022)--.       (062)
(032)     (034)     (002)     (020)     (001)     (021)
==29133==
==29133== HEAP SUMMARY:
==29133==     in use at exit: 0 bytes in 0 blocks
==29133==   total heap usage: 213 allocs, 213 frees, 9,063 bytes allocated
==29133==
==29133== All heap blocks were freed -- no leaks are possible
==29133==
==29133== For counts of detected and suppressed errors, rerun with: -v
==29133== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/binary\_trees$
```
