#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 *
 * Return: A pointer to the new head of the reversed list
 */

listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *first_half = *head;
	listint_t *second_half;

	if (head == NULL || *head == NULL)
		return (1);

	/** Find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/** Reverse the second half of the list */
	second_half = reverse_list(slow);

	/** Compare the first half and the reversed second half */
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
			return (0);
		first_half = first_half->next;
		second_half = second_half->next;
	}
    
	return (1);
}