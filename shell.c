#include "shell.h"

/**
 * shell - function of the shell
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array of environment variables
 *
 * Return: 0 on success
 */
int shell(int argc, char *argv[], char *envp[])
{
	char *line;
	char **args;
	int status, exit_command = 0, env_command = 0;
	(void) argc;
	(void) argv;

	do {

		if (isatty(STDIN_FILENO))
			printf(TERMINAL_PROMPT);
		line = read_line();
		args = split_line(line);

		if (strcmp(trim(line), "exit") == 0)
			exit_command = 1;
		else if (strcmp(trim(line), "env") == 0)
			env_command = 1;
		else
			status = execute(argv[0], args, envp);

		if (line != NULL)
			free(line);
		if (args != NULL)
			free(args);

		if (exit_command)
			exit(0);
		if (env_command)
			status = print_env(envp), env_command = 0;

	} while (status);

	return (0);
}
