#include "binary_trees.h"
#include <stdlib.h>

/**
 * build_avl - Recursive helper to build AVL tree
 * @array: Pointer to the first element
 * @start: Start index
 * @end: End index
 * @parent: Pointer to parent node
 * Return: Pointer to new node
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
    avl_t *node;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);

    node->n = array[mid];
    node->parent = parent;
    node->left = build_avl(array, start, mid - 1, node);
    node->right = build_avl(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Converts sorted array to AVL
 * @array: Pointer to array
 * @size: Size of array
 * Return: Root of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);
    return (build_avl(array, 0, size - 1, NULL));
}
