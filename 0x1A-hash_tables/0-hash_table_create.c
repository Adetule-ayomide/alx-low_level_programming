#include "hash_tables.h"
/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table or
 * If something went wrong, the function should return NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{

	hash_table_t *hash_t = {NULL};

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
	{
		return (NULL);
	}
	hash_t->size = size;
	hash_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}
	return (hash_t);
}
