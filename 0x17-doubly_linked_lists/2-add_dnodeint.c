#include "lists.h"

/**
 * add_dnodeint - function that adds a new node at the beginning of a list
 * @head: head node pointer
 * @n: new node integer
 * Return: the address of the new element if it success),
 * or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	};
	new->n = n;
	new->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	new->next = *head;
	*head = new;

	return (new);
}
