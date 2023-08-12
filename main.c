#include "shell.h"

/**
 * main - entry point
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array of environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp[])
{
	return (shell(argc, argv, envp));
}
