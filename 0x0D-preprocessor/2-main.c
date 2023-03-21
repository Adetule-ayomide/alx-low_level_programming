#include <stdlib.h>
#include <stdio.h>

/**
 * main - program that print the name of the file it's compiled from
 *
 * Return: Always 0 (success)
 */

int main()
{
	printf("%s\n" _FILE_);

	return (0);
}
