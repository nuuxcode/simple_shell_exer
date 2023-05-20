#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *_strtok(char *str, const char *delim)
{
	static char *lastToken = NULL; /* pointer to last token found */
	char *token = NULL;			   /* pointer to current token */
	if (str != NULL)
	{ /* new string to tokenize */
		lastToken = str;
	}
	else
	{ /* use previous string to continue tokenizing */
		if (lastToken == NULL)
		{ /* no previous string available */
			return NULL;
		}
		str = lastToken;
	}
	/* skip leading delimiters */
	str += strspn(str, delim);
	if (*str == '\0')
	{ /* end of string reached */
		lastToken = NULL;
		return NULL;
	}
	/* find end of current token */
	token = str;
	str = strpbrk(token, delim);
	if (str == NULL)
	{ /* last token in string */
		lastToken = NULL;
	}
	else
	{
		*str = '\0';
		lastToken = str + 1;
	}
	return token;
}
int main()
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	char *token = _strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, " ");
		exit(1);
	}

	return 0;
}
