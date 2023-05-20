#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
	char *lineptr;
	size_t n;
	ssize_t read_stdin;
	printf("$ ");
	getline(&lineptr, &n, stdin);
	free(lineptr);
	return (0);
	char *str = malloc(sizeof(char) * 100); // Allocate memory for the input string
	if (str == NULL)
	{
		perror("Failed to allocate memory for input string");
		return 1;
	}
	int i;
	for (i = 0; i < 19; i++) // Assign each character of the string one by one
	{
		str[i] = "This is a test string"[i];
		printf("%c-", "This is a test string"[i]);
	}
	char *token;

	token = strtok(str, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	free(str); // Free the memory allocated for the input string
	return 0;
}
