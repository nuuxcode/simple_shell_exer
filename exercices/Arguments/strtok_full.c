#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
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
