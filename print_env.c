#include "shell.h"

/**
 * print_env - prints the environment
 *
 * @envp: array of environment variables
 *
 * Return: 1 on success
 */
int print_env(char *envp[])
{
	int i = 0;

	while (envp[i] != NULL)
		printf("%s\n", envp[i++]);

	return (1);
}
