#include "hash_tables.h"

/**
 * key_index - function that gives you the index of a key.
 * @key: The key to be hashed
 * @size: The size of the array of the hash table
 * Return: the index at which the key/value pair should be stored
 * in the array of the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	hash_value = hash(key);

	return (hash_value % size);
}
