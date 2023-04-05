#include "lists.h"

/**
* free_listint2 - frees a linked list
* @head: linked list
* Return: nothing
*/
void free_listint2(listint_t **head)
{
	listint_t *sec, *temp;

	if (head != NULL)
	{
		sec = *head;

		while (sec != NULL)
		{

			temp = sec;

			sec = sec->next;

			free(temp);

		}
	*head = NULL;

	}
}
