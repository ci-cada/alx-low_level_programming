#include "main.h"
#include <string.h>

/**
 * append_text_to_file - append text at the end of a file
 * @filename: name of the file containing string to be appended
 * @text_content: pointer to the string we want to append
 * Return: 1 on success | -1 on failure
 * if filename is NULL return -1 | if text_content is NULL dont add anything
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int t_file, s_file, length;

	if (filename == NULL)
		return (-1);
	t_file = open(filename, O_WRONLY | O_APPEND);
	if (t_file == -1)
		return (-1);

	if (!text_content)
		return (1);

	length = strlen(text_content);

	s_file = write(t_file, text_content, length);
	if (s_file == -1)
		return (-1);

	s_file = close(t_file);
	if (s_file == -1)
		return (-1);

	return (1);
}

