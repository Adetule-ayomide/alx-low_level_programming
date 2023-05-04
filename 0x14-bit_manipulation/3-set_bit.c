#include "main.h"
/**
 * set_bit - Function that sets the value of a bit
 * @n: variable
 * @index: The position to be set
 * Return: -1 if failed and 1 if success
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n |= 1 << index;

	return (1);
}
