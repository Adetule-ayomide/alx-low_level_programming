#include "main.h"

/**
 * print_binary - The prototype that prints the binary representation
 * @n: Variable in the argument
 * Return: 0
 */

void print_binary(unsigned long int n)
{
	if (n > 0)
	{
		if (n > 1)
		print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
	else
	{
		_putchar('0');
	}
}
