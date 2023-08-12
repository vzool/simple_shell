#include "shell.h"

/**
 * split_line - splits a line into tokens
 *
 * @line: line to split
 *
 * Return: pointer to an array of tokens
 */
char **split_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int bufsize = 0;
	int i = 0;

	tokens = malloc(sizeof(char *) * (bufsize + 1));
	if (!tokens)
		perror("split_line"), exit(EXIT_FAILURE);

	token = strtok(line, DELIMITERS);
	while (token)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, sizeof(char *) * (bufsize + 1));
			if (!tokens)
				perror("split_line"), exit(EXIT_FAILURE);
		}

		token = strtok(NULL, DELIMITERS);
	}
	tokens[i] = NULL;

	return (tokens);
}
