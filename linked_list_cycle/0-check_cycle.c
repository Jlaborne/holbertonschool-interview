#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle using
 *               Floyd's Tortoise and Hare algorithm.
 * @list: Pointer to the head of the linked list.
 * Return: 1 if there is a cycle, 0 otherwise.
 */

int check_cycle(listint_t *list)
{
    listint_t *low = list, *speed = list;

    while (speed != NULL && speed->next != NULL)
    {
        low = low->next;  /* Déplacer le pointeur lent d'un pas */
        speed = speed->next->next;  /* Déplacer le pointeur rapide de deux pas */

        if (low == speed)  /* S'ils se rencontrent, il y a un cycle */
            return (1);
    }
    return (0);  /* Si le pointeur rapide atteint la fin, pas de cycle */
}