#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t nread;
	pid_t child_pid = 0;
	int status = 0;

	while (1)
	{
		printf("#cisfun$ ");
		n = 0;
		nread = getline(&cmd, &n, stdin);
		if (nread == -1) {
			printf("\n");
			exit(1);
		}
		cmd[nread - 1] = '\0';
		char *av[] = {cmd, NULL};
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("this is fork\n");
			execve(cmd, av, NULL);
		}
		wait(&status);
	}
	free(cmd);
	return (0);
}
