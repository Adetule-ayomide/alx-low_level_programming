#include "hash_tables.h"

/**
 * hash_table_print - function that print the hash table
 * @ht: hash table
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *curr;
	unsigned long int i;
	int sep;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr != NULL)
		{
			if (sep == 1)
				printf(", ");
			printf("'%s': '%s'", curr->key, curr->value);
			sep = 1;
			curr = curr->next;
		}
	}
	printf("}\n");
}
