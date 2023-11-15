#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(simple_shell)

{
	printf("simple_shell$ ");
}

void execute_command(char *simple_shell)

{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)

{
		execlp(command, command, NULL)
		perror("simple_shell");
		exit(EXIT_FAILURE);
}
	else if (pid < 0)

{
	perror("simple_shell");
	exit(EXIT_FAILURE);

}
else
{
	waitpid(pid, &status, 0);
}

int main(void)

{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	display_prompt();

	if (fgets(command, sizeof(command), stdin) == NULL)
		{

	printf("\n");
		break;
}

command[strcspn(command, "\n")] = '\0';

	if (strlen(command) > 0)
{
	execute_command(command);
}

	printf("Exiting simple_shell.\n");
	return (EXIT_SUCCESS);
}
