#include "lists.h"

/**
* print_listint - struct node variable in the prototype
* @h: A pointer to the next node
* Return: numNode
*/

size_t print_listint(const listint_t *h)
{
	int num_node = 0;

	while (h != NULL)
	{
		num_node++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (num_node);
}
