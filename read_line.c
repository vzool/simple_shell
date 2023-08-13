#include "shell.h"

/**
 * read_line - reads a line from stdin
 *
 * Return: pointer to the line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
			perror("read_line"), exit(EXIT_FAILURE);
	}

	return (line);
}
