#include "main.h"
/**
 * clear_bit - Function that sets the value of a bit
 * @n: A pointer
 * @index: Position to be set
 * Return: -1 if failed and 1 is success
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n &= ~(1 << index);

	return (1);
}
