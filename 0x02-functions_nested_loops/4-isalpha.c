#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: is the result to be printed
 * Return: 1 and 0 depending on the condition
 */

int _isalpha(int c)
{

	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

}
