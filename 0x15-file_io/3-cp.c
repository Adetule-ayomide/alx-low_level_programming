#include "main.h"
/**
 * error_close - check closing errors
 * @err_to: file to copy into
 * @err_from: file to copy from
 * Return: nothing
 */
void error_close(int err_to, int err_from)
{
	if (err_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err_to);
		exit(100);
	}
	if (err_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err_from);
		exit(100);
	}
}
/**
 * error_checks - check opening errors
 * @file_to: file to copy into
 * @file_from: file to copy from
 * @argv: argument vector
 * Return: nothing
 */
void error_checks(int file_to, int file_from, char *argv[])
{
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}
}
/**
 * main - starting point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int err_from, err_to, file_from, file_to;
	char buf[1024];
	ssize_t read_f, write_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_checks(file_to, file_from, argv);
	read_f = 1024;
	while (read_f == 1024)
	{
		read_f = read(file_from, buf, 1024);
		if (read_f == -1)
		{
			error_checks(file_to, file_from, argv);
		}
		write_to = write(file_to, buf, read_f);
		if (write_to == -1)
		{
			error_checks(file_to, file_from, argv);
		}
	}
	if (file_to == -1)
	{
		error_checks(file_to, file_from, argv);
	}
	err_from = close(file_from);
	err_to = close(file_to);
	error_close(err_to, err_from);
	return (0);
}
