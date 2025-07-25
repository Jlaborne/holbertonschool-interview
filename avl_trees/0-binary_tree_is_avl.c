#include "binary_trees.h"
#include <limits.h> /* For INT_MIN and INT_MAX */
#include <stdlib.h> /* For abs */

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * is_bst - Helper to check if tree is a valid BST
 * @tree: Pointer to current node
 * @min: Minimum valid value
 * @max: Maximum valid value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	lh = height(tree->left);
	rh = height(tree->right);

	if (abs(lh - rh) > 1)
		return (0);

	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);
	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
