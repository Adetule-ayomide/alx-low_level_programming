#include "lists.h"

/**
 * delete_dnodeint_at_index - A function that deletes a node from a
 * dlistint_t at a given index.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node to delete.
 *
 * Return: Upon success - 1.
 *         Otherwise - -1.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	dlistint_t *temp2;

	size_t count = 0;

	temp = *head;
	if (*head == NULL)
		return (-1);
	while (count < index - 1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (temp == NULL || temp->next == NULL)
		return (-1);
	temp2 = temp->next;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	free(temp2);
	return (1);
}
