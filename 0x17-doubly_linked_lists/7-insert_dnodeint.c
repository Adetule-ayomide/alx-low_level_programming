#include "lists.h"

/**
 * insert_dnodeint_at_index -  a function that inserts a new node
 * at a given position.
 * @h: a pointer of the head node
 * @idx: the given index
 * @n: integer of the new node
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp;
	dlistint_t *temp2;
	dlistint_t *new;
	size_t count = 0;

	new = malloc(sizeof(dlistint_t));
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	temp = *h;
	temp2 = temp;

	if (h == NULL)
		return (NULL);
	if (new == NULL)
		return (NULL);
	if (idx == 0)
	{
		new->next = temp;
		new->prev = NULL;
		if (temp != NULL)
			temp->prev = new;
		*h = new;
		return (new);
	}
	while (temp != NULL && count < idx - 1)
	{
		temp = temp->next;
		temp2 = temp->next->next;
		count++;
	}
	if (temp == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = temp2;
	new->prev = temp;
	temp->next = new;	
	return (new);
}
