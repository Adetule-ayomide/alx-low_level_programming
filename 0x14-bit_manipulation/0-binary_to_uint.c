#include "main.h"
/**
 * binary_to_uint - The prototype which convert binary to unsigned integer
 * @b: A pointer
 * Return: Integer if success or 0 if failed
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int integer = 0;

	if (*b == '\0')
		return (0);

	while (*b != '\0')
	{
		if (*b == '0')
		{
			integer = integer * 2;
		}
		else if (*b == '1')
		{
			integer = ((integer * 2) + 1);
		}
		else
			return (0);

		b++;
	}
	return (integer);
}
