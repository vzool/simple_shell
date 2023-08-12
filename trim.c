#include "shell.h"

/**
 * trim - remove leading and trailing spaces, tabs and newlines
 *
 * @str: string to trim
 *
 * Return: pointer to the trimmed string
 */
char *trim(char *str)
{
	int i = 0, j, k;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	k = j - 1;
	while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n')
		k--;
	str[k + 1] = '\0';

	return (str + i);
}
