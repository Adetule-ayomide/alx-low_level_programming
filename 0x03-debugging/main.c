#include "main.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Determines if a number is positivie, negative or zero.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	i = 0;
	positive_or_negative(i);
	
	srand(time(0));
	i = rand() - RAND_MAX / 2;
	if (i > 0)
	{
		printf("%d is positive\n", i);
	}
	else if (i == 0)
	{
		printf("%d is zero\n", i);
	}
	else if (i < 0)
	{
		printf("%d is negative\n", i);
	}
	
	return (0);

}
