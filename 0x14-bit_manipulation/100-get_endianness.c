#include <stdio.h>
#include "main.h"
/**
* get_endianness - checks the endianness.
* Return: 0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{
	unsigned int check = 1;
	char *dian = (char *)&check;

	return (*dian == 1);
}
