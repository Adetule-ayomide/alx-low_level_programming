#include "lists.h"

/**
 * print_list - Function prototype
 * @h: pointer
 * Description: singly linked list node structure
 * Return: Always 0 (success)
 */

size_t print_list(const list_t *h)
{
	size_t node_num = 0;

	while (h != NULL)
	{
	if (h->str == NULL)
	{
		printf("[0] %s\n", "(nil)");
	}
	else
	{
		printf("[%u] %s\n", h->len, h->str);
	}
	h = h->next;
	node_num++;
	}
	return (node_num);
}
