#include "main.h"
/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: The file name
 * @text_content: The text content
 * Return: -1 on error and 1 on success
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fc, c, write_func;

	if (filename == NULL)
	{
		return (-1);
	}

	fc = open(filename, O_WRONLY | O_APPEND);
	if (fc == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (c = 0; text_content[i]; i++)
		;

		write_func = write(fc, text_content, i);
		if (write_func == -1)
		{
			return (-1);
		}
	}

	close(fc);
	return (1);
}
