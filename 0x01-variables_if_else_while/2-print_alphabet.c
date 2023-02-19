#include <stdio.h>

/**
 * main - program that prints the alphabet in lowercase,followed by a new line
 *
 * Return: Always 0 (success)
 */

int main(void)
{

	char alp[26] = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
		int i;

	for (i = 0; i <= 26; i++)
	{
		putchar(alp[i]);
	}
	putchar('\n');
	return (0);
}
