#include <stdio.h>

extern char **environ;

int main()
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
