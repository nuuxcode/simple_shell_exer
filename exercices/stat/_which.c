#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	struct stat st;
	char *path = getenv("PATH");
	char *token;
	char *fullpath;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}

	token = strtok(path, ":");
	while (token)
	{
		fullpath = strdup(strcat(strcat(strdup(token), "/"), av[1]));
		if (stat(fullpath, &st) == 0)
		{
			printf("%s\n", fullpath);
			break;
		}
		free(fullpath);
		free(token);
		token = strtok(NULL, ":");
	}
	free(path);
	free(fullpath);
	return (0);
}

/*
"PATHx=A=value"
"PATHx==value"
PATHx= && str[len] == '='
0 variable exist (dont do anything)
0 variable doesnt exist (create new one with new value)
1 variable exist (overwrite the value)
1 variable doesnt exist (create....)
6
getenv()
strtok
access()
strcat
if (stat(av[i], &st) == 0)
get path variable value
	loop through every directory
	split it on : (semicolon) to an array (strtook)
		check if the directory is exist
			if its :
				concat directory path withe filename
					then give it stat and check the value
						if it exist
							print the whole path with filename
						if not
							check the next path*
	if file doesnt exist in any derctory, then exit program


*/
