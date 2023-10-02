#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- function that read text file print to STDOUT
 * @filename: is the text file being read
 * @letters: the number of letters to be read
 * Return: returns the actual number of letters it could read
 * and print if the file can not be opened or read, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

