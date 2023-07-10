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
	int file, length, var, out;
	char *checker;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	checker = malloc(sizeof(char) * letters);
	if (checker == NULL)
		return (0);

	read(file, checker, letters);
	checker[letters] = '\0';

	for (var = 0; checker[var] != '\0'; var++)
		length += 1;

	out = close(file);
	if (out != 0)
		exit(-1);

	out = write(STDOUT_FILENO, checker, length);
	if (out != length)
		return (0);

	free(checker);

	return (length);
}
