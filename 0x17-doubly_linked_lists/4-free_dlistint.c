#include "lists.h"

/**
 * free_dlistint - function that free dlistint
 * @head: a pointer of the head node
 * Return: success
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
