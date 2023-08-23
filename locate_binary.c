#include "shell.h"

/**
 * locate_binary - locates a binary path
 *
 * @command: command to locate
 * @envp: array of environment variables
 *
 * Return: path pointer to the binary, NULL on failure
 */
char *locate_binary(char *command, char *envp[])
{
	int i = 0;
	char *token = NULL, *full_path = NULL, *paths = NULL;
	struct stat st;

	return (command);
	if (command == NULL)
		return (NULL);
	if (access(command, F_OK) == 0)
		return (command);
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = strdup(envp[i] + (sizeof(char) * 5));
			token = strtok(paths, "=:");
			while (token != NULL)
			{
				full_path = malloc(sizeof(char) * (strlen(token) + strlen(command) + 2));
				if (!full_path)
					continue;
				sprintf(full_path, "%s/%s", token, command);
				if (stat(full_path, &st) == 0 && st.st_mode & S_IXUSR)
					return (full_path);
				token = strtok(NULL, "=:");
				if (full_path != NULL)
					free(full_path);
			}
			if (paths != NULL)
				free(paths);
		}
		i++;
	}
	return (command);
}
