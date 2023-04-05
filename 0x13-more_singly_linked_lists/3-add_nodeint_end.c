#include "lists.h"

/**
 * *add_nodeint_end - Struct node variable in the prototype
 * @head: Pointer to pointer
 * @n: variable of a number
 * Return: head
 */


listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode, *assume;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{

		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	assume = *head;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (assume->next != NULL)
		{
			assume = assume->next;
		}
		assume->next = newNode;
	}

	return (*head);
}
