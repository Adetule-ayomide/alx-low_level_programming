#include "lists.h"

/**
 * print_list - Function prototype
 * @h: pointer
 * Return: node_num
 */

size_t print_list(const list_t *h)
{
	size_t node_num;

	node_num = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		} else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		node_num++;
	};
	return (node_num);
}
