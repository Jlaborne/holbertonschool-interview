#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Allocates and initializes a new node
 * @str: String to duplicate into the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	node->next = node->prev = NULL;
	return (node);
}

/**
 * add_node_end - Adds a new node at the end of a circular doubly linked list
 * @list: Address of the pointer to the list
 * @str: String to duplicate into the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node, *tail;

	node = create_node(str);
	if (!node)
		return (NULL);

	if (!*list)
	{
		node->next = node->prev = node;
		*list = node;
	}
	else
	{
		tail = (*list)->prev;

		node->next = *list;
		node->prev = tail;
		tail->next = node;
		(*list)->prev = node;
	}
	return (node);
}

/**
 * add_node_begin - Adds a new node at the beginning of a circular doubly list
 * @list: Address of the pointer to the list
 * @str: String to duplicate into the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = add_node_end(list, str);
	if (node)
		*list = node;
	return (node);
}
