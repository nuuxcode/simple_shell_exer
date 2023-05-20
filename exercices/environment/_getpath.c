#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_getenv(char *name)
{
	extern char **environ;
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}

int main()
{
	char *mine = _getenv("PATH");
	char *token;
	if (mine)
		token = strtok(mine, ":");
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	printf("%s\n", mine);
	return (0);
}
