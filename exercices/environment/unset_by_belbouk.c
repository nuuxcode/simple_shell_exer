#include <stdio.h>

extern char **environ;

int main()
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		if (i >= 2 && env[i + 1])
		{
			env[i] = env[i + 1];
		}
		else if (!env[i + 1])
			env[i] = NULL;
		i++;
	}
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
// TERM_PROGRAM_VERSION=1.74.2
