#include "lists.h"

/**
 * *add_nodeint_end - Struct node variable in the prototype
 * @head: Pointer to pointer
 * @n: variable of a number
 * Return: head
 */


listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode, *tempNode;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
	{

		return (NULL);
	}
	newNode->n = n;
	newNode->next = NULL;

	tempNode = *head;
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}

	return (*head);
}
