#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("%p %p\n", (void *)env, (void *)environ);
	return (0);
}
