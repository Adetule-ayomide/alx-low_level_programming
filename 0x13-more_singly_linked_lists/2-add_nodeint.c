#include "lists.h"

/**
 * add_nodeint - Struct node variable in the prototype
 * @head: A pointer to pointer
 * @n: variable to a number
 * Return: *head
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *addNode;

	addNode = malloc(sizeof(listint_t));

	if (addNode == NULL)
	return (NULL);

	addNode->n = n;
	addNode->next = *head;
	*head = addNode;

	return (*head);
}
