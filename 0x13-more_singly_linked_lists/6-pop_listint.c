#include "lists.h"

/**
 * pop_listint - Struct node variable in the prototype
 * @head: A pointer to pointer
 * free: assume
 * Return: 0 if null and temp if success
 */

int pop_listint(listint_t **head)
{
	size_t temp;
	listint_t *assume, *nextNode;

	if (*head == NULL)
	{
		return (0);
	}

	assume = *head;
	nextNode = assume->next;
	temp = assume->n;
	free(assume);
	*head = nextNode;
	return (temp);
}
