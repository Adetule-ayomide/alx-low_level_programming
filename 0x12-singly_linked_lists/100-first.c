#include <stdio.h>

/**
 * before_main - calls function before main
 * Return: 0
 */
void before_main(void) __attribute__((constructor));
void before_main(void)
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}
