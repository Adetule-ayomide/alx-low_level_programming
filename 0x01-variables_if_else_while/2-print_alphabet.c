#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase,followed by a new line
 *
 * Return: Always 0 (success)
 */

int main(void)
{

	char alp[26] = "a b...y z";
		int i;

	for (i = 0; i <= 26; i++)
	{
		putchar(alp[i]);
	}
	putchar('\n');
	return (0);
}
