#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int elf_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 *  print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int check_it;

	printf("Magic:   ");

	for (check_it = 0; check_it < EI_NIDENT; check_it++)
	{
		printf("%02x ", e_ident[check_it]);

		if (check_it == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void print_class(unsigned char *e_ident)
{
	printf("Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
		break;
	}
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/

void print_data(unsigned char *e_ident)
{
	printf("Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
		break;
	}
}

/**
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/

void print_version(unsigned char *e_ident)
{
	printf("Version:                           %d",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
		printf(" (current)\n");
		break;
		default:
		printf("\n");
		break;
	}
}

/**
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/

void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
				break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
* print_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*/

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = (e_type >> 8);

	printf("Type:			");
	switch (e_type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown file type: %x>\n", e_type);
			break;
	}
}


/**
* print_entry - Prints the entry point of an ELF header.
* @elf_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int elf_entry, unsigned char *e_ident)
{
	printf("Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
		((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * check_elf - Checks if a file is an ELF file or not.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */

void check_elf(unsigned char *e_ident)
{

	if (e_ident[EI_MAG0] != ELFMAG0 ||
	e_ident[EI_MAG1] != ELFMAG1 ||
	e_ident[EI_MAG2] != ELFMAG2 ||
	e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: It's not an ELF file\n");
		exit(98);
	}
	if (e_ident[EI_CLASS] != ELFCLASS32 && e_ident[EI_CLASS] != ELFCLASS64)
	{
		dprintf(STDERR_FILENO, "Error: Invalid ELF class\n");
		exit(98);
	}
	if (e_ident[EI_DATA] != ELFDATA2LSB && e_ident[EI_DATA] != ELFDATA2MSB)
	{
		dprintf(STDERR_FILENO, "Error: Invalid ELF data encoding\n");
		exit(98);
	}

	printf("\nELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	print_abi(e_ident);
	print_type(((Elf64_Ehdr *)e_ident)->e_type, e_ident);
	print_entry(((Elf64_Ehdr *)e_ident)->e_entry, e_ident);
}

/**
 * main - It's Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @ac: The number of arguments supplied to the program.
 * @av: An array of pointers to the arguments.
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */

int main(int ac, char **av)
{
	int fd;
	unsigned char e_ident[EI_NIDENT];

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: %s elf_filename\n", av[0]);
		exit(98);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (read(fd, e_ident, EI_NIDENT) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	check_elf(e_ident);
	close_elf(fd);
	return (0);
}
