#include "lists.h"

/**
 * delete_nodeint_at_index - Struct node variable for the prototype
 * @head: A pointer to pointer
 * @index: number of the index
 * free: nextNode
 * Return: 1 if successful and -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prevNode, *nextNode;
	size_t i;

	prevNode = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prevNode != NULL; i++)
		{
			prevNode = prevNode->next;
		}
	}

	if (prevNode == NULL || (prevNode->next == NULL && index != 0))
	{
		return (-1);
	}
	nextNode = prevNode->next;

	if (index != 0)
	{
		prevNode->next = nextNode->next;
		free(nextNode);
	}
	else
	{
		free(prevNode);
		*head = nextNode;
	}

	return (1);
}
