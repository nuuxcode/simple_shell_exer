#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main()
{
	char *lineptr;
	size_t n = 0;
	printf("$ ");
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);
	free(lineptr);
	return (0);
}
