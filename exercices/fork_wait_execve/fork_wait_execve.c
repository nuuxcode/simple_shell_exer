#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	pid_t child_pid;
	int loop = 6;
	int status;
	char *av[] = {"/bin/ls", "-l", "/tmp", NULL};
	while (loop--)
	{
		child_pid = fork();
		printf("----\n(%d) The %d fork started.\n", child_pid, loop);
		if (child_pid == 0)
		{
			printf("this fork\n");
			execve(av[0], av, NULL);
			printf("this not gonna printf-------------");
		}
		wait(&status);
		printf("(%d) The %d fork finished.\n", child_pid, loop);
	}
	return (0);
}


/*
	main start
		loop 5 time
			exec fork
				fork start
					execve ls...
					exit
			wait for the previous fork
*/
