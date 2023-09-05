#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64

/**
 * print_error - prints an error message and exits with status 98
 * @message: the error message to print
 */

void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header - prints information from the ELF header
 * @elf_header: a pointer to the ELF header structure
 */

void print_elf_header(Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x%c", elf_header->e_ident[i],
				(i == EI_NIDENT - 1) ? '\n' : ' ');
	}
	printf("  Class:  %s\n",
			(elf_header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:   %s\n",
			(elf_header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" : "");
	printf("  Version: %d (current)\n", elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI: %s\n",
			(elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ?
			"UNIX - System V" : "");
	printf("  ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:   %s\n",
			(elf_header->e_type == ET_EXEC) ? "EXEC (Executable file)" : "");
	printf("  Entry point address: 0x%lx\n", (unsigned long)elf_header->e_entry);
}

/**
 * read_elf_header - reads the ELF header from a file
 * @filename: the name of the ELF file
 * @elf_header: a pointer to the ELF header structure
 * Return: 0 on success, exits with status 98 on error
 */

int read_elf_header(const char *filename, Elf64_Ehdr *elf_header)
{
	int fd;
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Error: Unable to open file");
	}

	bytes_read = read(fd, elf_header, sizeof(Elf64_Ehdr));

	close(fd);

	if (bytes_read == -1 || (size_t)bytes_read < sizeof(Elf64_Ehdr))
		print_error("Error: Unable to read ELF header");
	if (memcmp(elf_header->e_ident, ELFMAG, SELFMAG) != 0)
		print_error("Error: Not an ELF file");
	return (0);
}

/**
 * main - entry point of the program
 * @argc: the number of command-line arguments
 * @argv: an array of pointers to the arguments
 * Return: 0 on success, exits with status 98 on error
 */

int main(int argc, char *argv[])
{
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	if (read_elf_header(argv[1], &elf_header) == 0)
	{
		print_elf_header(&elf_header);
	}
	return (0);
}
