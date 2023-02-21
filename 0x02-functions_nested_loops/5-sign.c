#include "main.h"

/**
 * print_sign - prints the sign of a number
 * @n: The int to check is n
 * Return: 1 and 0 depending on the condition
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-')
		return (-1);
	}
	else
	{
		_purchar('0')
		return (0);
	}

}
