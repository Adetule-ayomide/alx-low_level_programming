#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: is a char to be checked
 * Returns: 1 and 0 depending on the condition
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
