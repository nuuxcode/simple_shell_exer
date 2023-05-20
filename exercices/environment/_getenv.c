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
	char *original = getenv("PATH");
	char *mine = _getenv("PATH");
	if (original)
		printf("%s\n", original);
	if (mine)
		printf("%s\n", mine);
	return (0);
}
