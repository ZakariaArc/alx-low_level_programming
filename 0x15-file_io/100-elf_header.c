#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkElfFile(unsigned char *e_ident);
void printElfMagicNumbers(unsigned char *e_ident);
void printElfClass(unsigned char *e_ident);
void printElfDataEncoding(unsigned char *e_ident);
void printElfVersion(unsigned char *e_ident);
void printElfOSABI(unsigned char *e_ident);
void printElfABI(unsigned char *e_ident);
void printElfFileType(unsigned int e_type, unsigned char *e_ident);
void printElfEntryPoint(unsigned long int e_entry, unsigned char *e_ident);
void closeElfFile(int elf);

/**
 * checkElfFile - checks if a file is an ELF file
 * @e_ident: a pointer to an array containing the ELF magic numbers
 * Description: if the file is not an ELF file, it exits with code 98
 */

void checkElfFile(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printElfMagicNumbers - prints the magic numbers of an ELF header
 * @e_ident: a pointer to an array containing the ELF magic numbers
 * Description: magic numbers are separated by spaces
 */

void printElfMagicNumbers(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printElfClass - prints the class of an ELF header
 * @e_ident: a pointer to an array containing the ELF class
 */

void printElfClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

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
	}
}

/**
 * printElfDataEncoding - prints the data encoding of an ELF header
 * @e_ident: a pointer to an array containing the ELF data encoding
 */

void printElfDataEncoding(unsigned char *e_ident)
{
	printf("  Data:                              ");

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
	}
}

/**
 * printElfVersion - prints the version of an ELF header
 * @e_ident: a pointer to an array containing the ELF version
 */

void printElfVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
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
 * printElfOSABI - prints the OS/ABI of an ELF header
 * @e_ident: a pointer to an array containing the ELF OS/ABI
 */

void printElfOSABI(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

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
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printElfABI - prints the ABI version of an ELF header
 * @e_ident: a pointer to an array containing the ELF ABI version
 */

void printElfABI(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * printElfFileType - prints the file type of an ELF header
 * @e_type: the ELF type
 * @e_ident: a pointer to an array containing the ELF class
 */

void printElfFileType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * printElfEntryPoint - prints the entry point of an ELF header
 * @e_entry: the address of the ELF entry point
 * @e_ident: a pointer to an array containing the ELF class
 */

void printElfEntryPoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
					((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * closeElfFile - closes an ELF file
 * @elf: the file descriptor of the ELF file
 * Description: if the file cannot be closed, it exits with code 98
 */

void closeElfFile(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - displays the information contained in the
 *        ELF header at the start of an ELF file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 on success
 * Description: if the file is not an ELF File or
 *              the function fails, it exits with code 98
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, readResult;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	readResult = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (readResult == -1)
	{
		free(header);
		closeElfFile(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElfFile(header->e_ident);
	printf("ELF Header:\n");
	printElfMagicNumbers(header->e_ident);
	printElfClass(header->e_ident);
	printElfDataEncoding(header->e_ident);
	printElfVersion(header->e_ident);
	printElfOSABI(header->e_ident);
	printElfABI(header->e_ident);
	printElfFileType(header->e_type, header->e_ident);
	printElfEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeElfFile(fileDescriptor);
	return (0);
}
