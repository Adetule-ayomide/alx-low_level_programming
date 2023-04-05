#include "lists.h"

/**
 * get_nodeint_at_index - Struct node variable in a prototype
 * @head: A pointer
 * Return: head

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t i;

	for (i = 0; i < index && head != NULL; i++)
	{
		head = head->next;
	}

	return (head);
}
