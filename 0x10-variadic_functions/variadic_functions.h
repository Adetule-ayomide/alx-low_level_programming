#ifndef VARIADIC_H
#define VARIADIC _H

#include <stdio.h>
#include <stdlib.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct format - Data type of a format.
 * @op: Format.
 * @f: Function.
 *
 */

typedef struct format
{
	char *op;
	void (*f)(va_list all);
} f;

#endif
