#include "lists.h"

/**
 * sum_dlistint - a function that returns the sum of
 * all the data (n) of a linked list.
 * @head: a pointer of the head node
 * Return: 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp;
	size_t sum = 0;

	temp = head;
	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
