#include "main.h"
#define BUF_SIZE 1024

/**
* main - main
* @argc: number of arguments
* @argv: a pointer point to the array of arguments
* Return: Always 0
**/

int main(int argc, char **argv)
{
	int file_1, file_2, s_file1, s_file2;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (0);

	file_2 = open(argv[1], O_RDONLY);
	error_98(file_2, buffer, argv[1]);
	file_1 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	error_99(file_1, buffer, argv[2]);
	do {
		s_file1 = read(file_2, buffer, BUF_SIZE);
		if (s_file1 == 0)
			break;
		error_98(s_file1, buffer, argv[1]);
		s_file2 = write(file_1, buffer, s_file1);
		error_99(s_file2, buffer, argv[2]);
	} while (s_file2 >= BUF_SIZE);
	s_file1 = close(file_1);
	error_100(s_file1, buffer);
	s_file1 = close(file_2);
	error_100(s_file1, buffer);
	free(buffer);
	return (0);
}

/**
* error_98 - checks error 98
* @file_1: the value to check
* @buffer: the buffer
* @argv: argument
**/
void error_98(int file_1, char *buffer, char *argv)
{

	if (file_1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
		free(buffer);
		exit(98);
	}
}

/**
* error_99 - checks error 99
* @file_1: value to check
* @buffer: the buffer
* @argv: argument
*/
void error_99(int file_1, char *buffer, char *argv)
{
	if (file_1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
		free(buffer);
		exit(99);
	}
}
/**
* error_100 - checks error 100
* @file_1: the value to check
* @buffer: the buffer
*/
void error_100(int file_1, char *buffer)
{
	if (file_1 < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file_1);
		free(buffer);
		exit(100);
	}
}
