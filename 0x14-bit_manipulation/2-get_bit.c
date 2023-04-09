#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: integer
 * @index: position of the integer to be move
 * Return: -1 if failed and cal if success
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	unsigned long int cal;

	cal = n >> index;

	cal &= 1;
	return (cal);
}
