#include "shell.h"

/**
 * execute - executes a command
 *
 * @app_name: name of the application
 * @args: array of arguments
 * @envp: array of environment variables
 *
 * Return: 1 on success, 0 on failure
 */
int execute(char *app_name, char **args, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror(app_name);
		return (0);
	}
	else if (pid == 0)
	{
		if (args[0] == NULL)
			return (1);
		if (execve(locate_binary(args[0], envp)/*, args, envp*/, NULL, NULL) == -1)
		{
			perror(app_name);
			return (0);
		}
	}
	else
		wait(&status);

	return (1);
}
