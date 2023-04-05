#include "lists.h"

/**
 * reverse_listint - Struct node variable in the prototype
 * @head: A pointer to pointer
 * Return: head
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *current, *next = NULL;

	current = *head;

	for (; current != NULL;)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}
