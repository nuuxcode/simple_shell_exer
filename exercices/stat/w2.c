#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 1;
	char *path;
	char *str;
	char *con;

	path = getenv("PATH");
	con = malloc(sizeof(char));
	char *path_copy = strdup(path);
	str = strtok(path_copy, ":");
	while (str != NULL)
	{
		con = malloc(sizeof(char));
		con = realloc(con, 1000);
		strcat(con, str);
		strcat(con, "/");
		strcat(con, argv[i]);
		printf("line 3 : %s\n", con);
		if (access(con, F_OK) == 0)
			printf("%s\n", con);
		free(con);
		str = strtok(NULL, ":");
	}
	free(path_copy);
	return 0;
}
/// usr/local/sbin
