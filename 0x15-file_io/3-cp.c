#include "main.h"

#define BUFFER_SIZE 1024

/**
 * __exit - prints error messages and exits with an exit code
 * @exit_code: either the exit code or file descriptor
 * @filename: the name of either source_file or destination_file
 * @fd: the file descriptor
 * Return: 0 on success
 */

int __exit(int exit_code, char *filename, int fd)
{
    switch (exit_code)
    {
    case 97:
        dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
        exit(exit_code);
    case 98:
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
        exit(exit_code);
    case 99:
        dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", filename);
        exit(exit_code);
    case 100:
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(exit_code);
    default:
        return (0);
    }
}

/**
 * main - create a copy of a file
 * @argc: the argument counter
 * @argv: the argument vector
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
    int source_fd, destination_fd;
    int read_status, write_status;
    int close_source, close_destination;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        __exit(97, NULL, 0);

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1)
        __exit(98, argv[1], 0);

    destination_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
    if (destination_fd == -1)
        __exit(99, argv[2], 0);

    while ((read_status = read(source_fd, buffer, BUFFER_SIZE)) != 0)
    {
        if (read_status == -1)
            __exit(98, argv[1], 0);

        write_status = write(destination_fd, buffer, read_status);
        if (write_status == -1)
            __exit(99, argv[2], 0);
    }

    close_source = close(source_fd);
    if (close_source == -1)
        __exit(100, NULL, source_fd);

    close_destination = close(destination_fd);
    if (close_destination == -1)
        __exit(100, NULL, destination_fd);

    return (0);
}
