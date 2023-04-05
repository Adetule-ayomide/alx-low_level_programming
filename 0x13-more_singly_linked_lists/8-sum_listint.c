#include "lists.h"
/**
 * sum_listint - Struct node variable in the prototype
 * @head: A pointer
 * Return: sum
 */

int sum_listint(listint_t *head)
{
	size_t sum = 0;

	while (head != NULL)
	{

		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
