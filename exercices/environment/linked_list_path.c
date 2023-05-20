#include <stdio.h>

struct Node
{
	char *value;
	struct Node *next;
};
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

void add_End(struct Node **head, char *value)
{
	struct Node *newNode;
	struct Node *current;
	newNode = malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current = current->next;
	}
}

int main()
{
	struct Node *head = NULL;
	char *mine = _getenv("PATH");
	char *token;
	if (mine)
		token = strtok(mine, ":");
	while (token)
	{
		insertBeg(&head, token);
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	printf("%s\n", mine);

	return (0);
}
