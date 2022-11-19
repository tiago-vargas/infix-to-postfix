#include <stdio.h>
#include <stdlib.h>

#define SIZE 200
#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

void tokenize(char string[], out char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 1; i < SIZE; i++)
		tokens[i] = strtok(NULL, " ");
}

char *convert(char input[])
{
	char *elements[SIZE];
	tokenize(input, out elements);

	char *operator = elements[1];
	char *first_number = elements[0];
	char *second_number = elements[2];

	char *result = malloc((sizeof (char)) * 1000);
	sprintf(result, "%s %s %s", first_number, second_number, operator);

	return result;
}
