#include <stdio.h>
#include <stdlib.h>

#define SIZE 200
#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

bool is_operator(char *string)
{
	char c = string[0];

	return c == '+' || c == '-' || c == '*' || c == '/';
}

void tokenize(char string[], out char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 1; i < SIZE; i++)
		tokens[i] = strtok(NULL, " ");
}

char *convert(char input[])
{
	char *result = malloc((sizeof (char)) * 1000);

	char *elements[SIZE];
	tokenize(input, out elements);

	char *first_number = elements[0];
	sprintf(result, "%s", first_number);

	int i = 0;
	while (elements[i] != NULL)
	{
		if (is_operator(elements[i]))
		{
			char *operator = elements[i];
			char *number_after_operator = elements[i + 1];

			sprintf(result, "%s %s %s", result, number_after_operator, operator);
		}

		i++;
	}

	return result;
}
