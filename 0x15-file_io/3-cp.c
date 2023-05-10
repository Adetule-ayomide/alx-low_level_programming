#include "main.h"
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
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
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
	int file_from, file_to;
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
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		write_to = write(file_to, buf, read_f);
		if (write_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
