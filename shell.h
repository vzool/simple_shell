#ifndef HEADER_SHELL
#define HEADER_SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DELIMITERS " \t\r\n\a"
#define TERMINAL_PROMPT "$ "
char *read_line(void);
char **split_line(char *line);
char *trim(char *str);
int print_env(char *envp[]);
char *locate_binary(char *command, char *envp[]);
int execute(char *app_name, char **args, char **envp);
int shell(int argc, char *argv[], char *envp[]);
#endif
