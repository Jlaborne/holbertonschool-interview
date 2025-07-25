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

### 31.

Write a function that checks if a binary tree is a valid [AVL Tree](/rltoken/702dClPKf4JcLP0unKbwgw "AVL Tree")

- Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Your function must return `1` if `tree` is a valid AVL Tree, and `0` otherwise
- If `tree` is `NULL`, return `0`

Properties of an AVL Tree:

- An AVL Tree is a BST
- The difference between heights of left and right subtrees cannot be more than one
- The left and right subtree each must also be a binary search tree

Note: In order for the main file to compile, you are provided with [this static library](https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/interviews/484/libavl.a "this static library"). This library won’t be used during correction, its only purpose is for testing.

```
alex@/tmp/binary\_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary\_trees.h"

/\*\*
 \* basic\_tree - Build a basic binary tree
 \*
 \* Return: A pointer to the created tree
 \*/
binary\_tree\_t \*basic\_tree(void)
{
    binary\_tree\_t \*root;

    root = binary\_tree\_node(NULL, 98);
    root->left = binary\_tree\_node(root, 12);
    root->right = binary\_tree\_node(root, 128);
    root->left->right = binary\_tree\_node(root->left, 54);
    root->right->right = binary\_tree\_node(root, 402);
    root->left->left = binary\_tree\_node(root->left, 10);
    return (root);
}

/\*\*
 \* main - Entry point
 \*
 \* Return: Always 0 (Success)
 \*/
int main(void)
{
    binary\_tree\_t \*root;
    int avl;

    root = basic\_tree();

    binary\_tree\_print(root);
    avl = binary\_tree\_is\_avl(root);
    printf("Is %d avl: %d\\n", root->n, avl);
    avl = binary\_tree\_is\_avl(root->left);
    printf("Is %d avl: %d\\n", root->left->n, avl);

    root->right->left = binary\_tree\_node(root->right, 97);
    binary\_tree\_print(root);
    avl = binary\_tree\_is\_avl(root);
    printf("Is %d avl: %d\\n", root->n, avl);

    root = basic\_tree();
    root->right->right->right = binary\_tree\_node(root->right->right, 430);
    binary\_tree\_print(root);
    avl = binary\_tree\_is\_avl(root);
    printf("Is %d avl: %d\\n", root->n, avl);

    root->right->right->right->left = binary\_tree\_node(root->right->right->right, 420);
    binary\_tree\_print(root);
    avl = binary\_tree\_is\_avl(root);
    printf("Is %d avl: %d\\n", root->n, avl);
    return (0);
}
alex@/tmp/binary\_trees$ gcc -Wall -Wextra -Werror -pedantic binary\_tree\_print.c 0-main.c 0-binary\_tree\_is\_avl.c -L. -lavl -o 0-is\_avl
alex@/tmp/binary\_trees$ ./0-is\_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
alex@/tmp/binary\_trees$
```
