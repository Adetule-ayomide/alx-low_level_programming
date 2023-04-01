#include "lists.h"

/**
 * add_node_end - Addition of node
 * @str: string - (malloc'ed string)
 * @head: Head of the string
 * Return: new_node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	size_t i;

	i = 0;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);

	while (str[i] != '\0')
	{
		i++;
	}
	new_node->len = i;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
