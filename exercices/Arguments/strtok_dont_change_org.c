#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim)
{
    static char *nextToken = NULL;
    char *token;
    char *copy = NULL;

    if (str != NULL)
    {
        copy = (char *)malloc(strlen(str) + 1);
        strcpy(copy, str);
        copy[strlen(str)] = '\0'; // Ensure copy is null-terminated
        nextToken = copy;
    }

    if (nextToken == NULL || *nextToken == '\0')
    {
        free(copy); // Free the copy when no more tokens are found
        return NULL;
    }

    token = nextToken;
    nextToken = strpbrk(nextToken, delim);

    if (nextToken != NULL)
    {
        *nextToken = '\0';
        nextToken++;
    }

    return token;
}

int main()
{
    char original[] = "";

    char *token = my_strtok(original, " ");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, " ");
    }

    printf("Original string: %s\n", original);

    return 0;
}
