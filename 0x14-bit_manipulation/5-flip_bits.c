#include "main.h"
/**
* flip_bits - Bits is needed to flip from one number to another
* @n: The number
* @m: destination number
* Return: the number of bits
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flp = n ^ m;
	unsigned int numbit = 0;

	while (flp)
	{
		numbit += flp & 1;
		flp >>= 1;
	}
	return (numbit);
}
