#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	int i;
	(void)ac;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
