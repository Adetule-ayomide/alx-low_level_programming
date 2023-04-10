#include "main.h"

/**
 * create_file - Function that creates a file
 * @filename: The is file name
 * @text_content: The text content
 * Return: -1 on failed 1 on success
 */

int create_file(const char *filename, char *text_content)
{
	int i = 0;

	int write_func;

	int fc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fc == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		text_content = "";
	}

	while (text_content[i] != '\0')
	{
		i++;
	}

	write_func = write(fc, text_content, i);

	if (write_func == -1)
	{
		return (-1);
	}

	close(fc);

	return (1);
}
