#include "lists.h"

/**
 * *insert_nodeint_at_index - Struct node variable in the prototype
 * @head: A pointer to pointer
 * @idx: index
 * @n: number of node
 * Return: newNode
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *previousNode, *newNode;
	size_t i = 0;

	previousNode = *head;


	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && previousNode != NULL; i++)
		{
			previousNode = previousNode->next;
		}
	}

	if (previousNode == NULL && idx != 0)
	{
		return (NULL);
	}
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	return (NULL);
	newNode->n = n;

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		newNode->next = previousNode->next;
		previousNode->next = newNode;
	}

	return (newNode);
}
