#include "lists.h"

/**
* print_listint - struct node variable in the prototype
* @h: A pointer to the next node
* Return: numNode
*/

size_t print_listint(const listint_t *h)
{
	int numNode = 0;

	while (h != NULL)
	{
		numNode++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (numNode);
}
