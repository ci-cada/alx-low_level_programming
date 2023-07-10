#include "main.h"
#include <string.h>

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: pointer to the string we want to write
 *
 * Return: 1 on success | -1 0n failure
 * if filename is NULL return -1
 * if text_content is NULL create an empty file and give rw-------
 */

int create_file(const char *filename, char *text_content)
{
	int t_file, s_file, length;

	if (filename == NULL)
		return (-1);

	t_file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (t_file != 0)
		return (-1);

	if (text_content == NULL)
		return (1);

	length = strlen(text_content);

	s_file = write(t_file, text_content, length);
	if (s_file != length)
		return (-1);

	s_file = close(t_file);

	return (1);
}
