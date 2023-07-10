#include "main.h"
#include <string.h>

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: pointer to the string we want to write
 *
 * Return: 1 on success | -1 0n failure
 * if filename is NULL return -1
 */

int create_file(const char *filename, char *text_content)
{
	int file, var, size;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	size = strlen(text_content);

	var = write(file, text_content, size);
	if (var != size)
		return (-1);

	var = close(file);

	return (1);
}
