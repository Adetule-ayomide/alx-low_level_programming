#include "main.h"
/**
 * binary_to_uint - The prototype which convert binary to unsigned integer
 * @b: A pointer
 * Return: Integer if success or 0 if failed
 */
unsigned int binary_to_uint(const char *b)
{
        unsigned integer = 0;
        int length, binary;

        if (!b)
                return (0);

        for (length = 0; b[length] != '\0'; len++)
                ;

        for (length--, binary = 1; length >= 0; length--, binary *= 2)
        {
                if (b[length] != '0' && b[length] != '1')
                {
                        return (0);
                }

                if (b[length] & 1)
                {
			integer += binary;
                }
        }

        return (integer);
}

