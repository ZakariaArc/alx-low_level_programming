#include "main.h"
/**
 * create_file - creates a file with the given text content
 * @filename: the name of the file to create
 * @text_content: A NULL-terminated string to write to the file
 * Return: on success 1, on failure -1
 */

int create_file(const char *filename, char *text_content)
{
    int fd, write_status;
    mode_t mode = S_IRUSR | S_IWUSR;

    if (filename == NULL)
        return (-1);
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1)
        return (-1);
    if (text_content != NULL)
    {
        write_status = write(fd, text_content, strlen(text_content));
        if (write_status == -1)
        {
            close(fd);
            return (-1);
        }
    }
    close(fd);
    return (1);
}
