#include "main.h"
int open_source_file(const char *filename);
int open_destination_file(const char *filename);
void copy_file_contents(int source_fd, int destination_fd);
void close_file(int fd);

/**
 * main - copies the content of a file to another file
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 * Return: 0 on success, or an exit code on failure
 */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	source_fd = open_source_file(argv[1]);
	destination_fd = open_destination_file(argv[2]);

	copy_file_contents(source_fd, destination_fd);

	close_file(source_fd);
	close_file(destination_fd);

	return (0);
}

/**
 * open_source_file - opens the source file for reading
 * @filename: the name of the source file
 * Return: the file descriptor of the opened source file
 */

int open_source_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_destination_file - opens the destination file for writing
 * @filename: the name of the destination file
 * Return: the file descriptor of the opened destination file.
 */

int open_destination_file(const char *filename)
{
	int fd = open(filename,
			O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file_contents - copies the contents of the source
 *                      file to the destination file
 * @source_fd: the file descriptor of the source file
 * @destination_fd: the file descriptor of the destination file
 */

void copy_file_contents(int source_fd, int destination_fd)
{
	char buffer[BUF_SIZE];
	ssize_t n_read, n_written;

	while ((n_read = read(source_fd, buffer, BUF_SIZE)) > 0)
	{
		n_written = write(destination_fd, buffer, n_read);
		if (n_written == -1)
		{
			dprintf(2, "Error: Can't write to destination file\n");
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(2, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * close_file - closes a file descriptor
 * @fd: the file descriptor to close
 */

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
