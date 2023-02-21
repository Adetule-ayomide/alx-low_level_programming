#include "main.h"

/**
 * print_last_digit - prints the last digit of a number in the task
 * @n: n is the value to be printed
 * Return: value of the last number
 */

int print_last_digit(int n)
{
	int ln = (n % 10);

	if (ln < 0)
		ln *= -1;

	_putchar(ln + '0');

	return (0);
}
