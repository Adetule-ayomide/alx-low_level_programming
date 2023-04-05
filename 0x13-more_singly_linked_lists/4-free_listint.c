#include "lists.h"

/**
 * free_listint - Struct node variable of the prototype
 * @head: A Pointer
 * free: temporary
 */


void free_listint(listint_t *head)
{
	listint_t *temporary;

	while (head != NULL)
	{
		temporary = head;
		head = head->next;
		free(temporary);
	}
}
