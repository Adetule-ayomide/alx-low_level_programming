#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @letters: The letters to read read through
 * @filename: The file name
 * Return: write_func on success and 0 if failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t txtfile;
	ssize_t read_func, write_func;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}

	txtfile = open(filename, O_RDONLY);

	if (txtfile == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		return (0);
	}
	read_func = read(txtfile, buffer, letters);
	write_func = write(STDOUT_FILENO, buffer, read_func);

	close(txtfile);
	free(buffer);
	return (write_func);
}
