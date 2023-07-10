#include "main.h"

/**
 * read_textfile - reads a text file and prints to the STDOUT
 * @filename: name of the file to be read
 * @letters: maximum number of letters to be read and printed
 *
 * Return: actual number of letters it could read and print
 * if filename is NULL return 0
 * if write fails return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fail, length, i, result;
	char *checker;

	if (filename == NULL)
		return (0);

	fail= open(filename, O_RDONLY);
	if (fail != 0 )
		return (0);

	checker = malloc(sizeof(char) * letters);
	if (checker == NULL)
		return (0);

	read(fail, checker, letters);
	checker[letters] = '\0';

	for (i = 0; checker[i] != '\0'; i++)
		length += 1;

	result = close(fail);
	if (result == -1)
		exit(-1);

	result = write(STDOUT_FILENO, checker, length);
	if (result != length)
		return (0);

	free(checker);

	return (length);
}
