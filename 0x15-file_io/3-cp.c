#include "main.h"

#define BUFFER_SIZE 1024

char *allocate_buffer(char *file);
void close_fd(int fd);

/**
 * allocate_buffer - allocates 1024 bytes for a buffer
 * @file: the name of the file for which the buffer is allocated
 * Return: the pointer to the newly-allocated buffer
 */

char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't allocate buffer for file %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_fd - closes file descriptors
 * @fd: the file descriptor to be closed
 */

void close_fd(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 on success
 * Description: if the argument count is incorrect - exit code 97
 *              if file_from does not exist or cannot be read - exit code 98
 *              if file_to cannot be created or written to - exit code 99
 *              if file_to or file_from cannot be closed - exit code 100
 */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_status, write_status;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}
	buffer = allocate_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_status = read(source_fd, buffer, BUFFER_SIZE);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (source_fd == -1 || read_status == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		write_status = write(destination_fd, buffer, read_status);
		if (destination_fd == -1 || write_status == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		read_status = read(source_fd, buffer, BUFFER_SIZE);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_status > 0);
	free(buffer);
	close_fd(source_fd);
	close_fd(destination_fd);
	return (0);
}
