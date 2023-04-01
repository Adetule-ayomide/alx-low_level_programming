#include "lists.h"

/**
 * add_node_end - Addition of node end
 * @str:string: (malloc'ed string)
 * @head: Hhead of the node
 * Return: Head of the null
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;
	size_t i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	for (i = 0; str[i]; i++)
		;

	new->len = i;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
	return (*head);
}
