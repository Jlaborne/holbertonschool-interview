#include "lists.h"

/**
 * find_listint_loop - Finds the node where a loop starts in a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Address of the node where the loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head || !head->next)
		return (NULL);

	/* Step 1: Detect if there is a loop using Floyd’s cycle-finding */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		/* Loop detected */
		if (slow == fast)
		{
			slow = head;

			/* Step 2: Find the start of the loop */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow); /* Start of the loop */
		}
	}

	return (NULL); /* No loop */
}
