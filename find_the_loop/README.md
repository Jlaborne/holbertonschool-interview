## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `and -pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- No standard library functions allowed. Any use of functions like `printf`, `puts`, `calloc`, `realloc` etc… is forbidden
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `lists.h`
- Don’t forget to push your header file
- All your header files should be include guarded
- Please use this `lists.h`:

```
#ifndef \_LISTS\_H\_
#define \_LISTS\_H\_

#include <stddef.h>

/\*\*
 \* struct listint\_s - singly linked list
 \* @n: integer
 \* @next: points to the next node
 \*
 \* Description: singly linked list node structure
 \* for Holberton project
 \*/
typedef struct listint\_s
{
    int n;
    struct listint\_s \*next;
} listint\_t;

listint\_t \*add\_nodeint(listint\_t \*\*head, const int n);
size\_t print\_listint\_safe(const listint\_t \*head);
size\_t free\_listint\_safe(listint\_t \*\*h);

listint\_t \*find\_listint\_loop(listint\_t \*head);

#endif
```

## Tasks

### 103.

Write a function that finds the loop in a linked list.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Returns: The address of the node where the loop starts, or `NULL` if there is no loop
- You are not allowed to use `malloc`, `free` or arrays
- You can only declare a maximum of two variables in your function

Note: In order to compile the main file, you are provided with [this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/472/libloop.a "this static library"). This library won’t be used during the correction; Its only purpose is for testing.

```
alexa@ubuntu:~/find\_the\_loop$ cat 0-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/\*\*
 \* main - check the code for Holberton School students.
 \*
 \* Return: Always 0.
 \*/
int main(void)
{
    listint\_t \*head;
    listint\_t \*head2;
    listint\_t \*node;

    head2 = NULL;
    add\_nodeint(&head2, 0);
    add\_nodeint(&head2, 1);
    add\_nodeint(&head2, 2);
    add\_nodeint(&head2, 3);
    add\_nodeint(&head2, 4);
    add\_nodeint(&head2, 98);
    add\_nodeint(&head2, 402);
    add\_nodeint(&head2, 1024);
    print\_listint\_safe(head2);
    node = find\_listint\_loop(head2);
    if (node != NULL)
    {
        printf("Loop starts at \[%p\] %d\\n", (void \*)node, node->n);
    }
    free\_listint\_safe(&head2);
    head = NULL;
    node = add\_nodeint(&head, 0);
    add\_nodeint(&head, 1);
    add\_nodeint(&head, 2);
    add\_nodeint(&head, 3);
    add\_nodeint(&head, 4);
    add\_nodeint(&head, 5);
    add\_nodeint(&head, 6);
    node->next = add\_nodeint(&head, 7);
    add\_nodeint(&head, 98);
    add\_nodeint(&head, 402);
    add\_nodeint(&head, 1024);
    print\_listint\_safe(head);
    node = find\_listint\_loop(head);
    if (node != NULL)
    {
        printf("Loop starts at \[%p\] %d\\n", (void \*)node, node->n);
    }
    free\_listint\_safe(&head);
    return (0);
}
alexa@ubuntu:~/find\_the\_loop$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find\_loop.c -L. -lloop -o main
alexa@ubuntu:~/find\_the\_loop$ ./main
\[0x13700f0\] 1024
\[0x13700d0\] 402
\[0x13700b0\] 98
\[0x1370090\] 4
\[0x1370070\] 3
\[0x1370050\] 2
\[0x1370030\] 1
\[0x1370010\] 0
\[0x1370560\] 1024
\[0x1370540\] 402
\[0x1370010\] 98
\[0x1370030\] 7
\[0x1370050\] 6
\[0x1370070\] 5
\[0x1370090\] 4
\[0x13700b0\] 3
\[0x13700d0\] 2
\[0x13700f0\] 1
\[0x1370110\] 0
-> \[0x1370030\] 7
Loop starts at \[0x1370030\] 7
alexa@ubuntu:~/find\_the\_loop$
```

If you want to use source file instead of the `libloop.a` library, please use this file [lib.c](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/text/2021/1/79eebf4f9215073644b8cd766a88c8a3f3a0fd88.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20250725%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20250725T113605Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=d861c85040d5f4d48b162313abd6ec3c9cc00be9f743688da08f55d0158bc71d "lib.c")

And compile it with this command: `$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main`
