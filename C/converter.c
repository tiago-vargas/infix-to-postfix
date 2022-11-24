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
	char *result = malloc((sizeof (char)) * 1000);

	char *elements[SIZE];
	tokenize(input, out elements);

	char *first_number = elements[0];
	char *result = first_number;

	/* is length of elements >= 2? */
	if (elements[1] != NULL)
	{
		char *first_operator = elements[1];
		char *second_number = elements[2];

		sprintf(result, "%s %s %s", first_number, second_number, first_operator);
	}

	/* is length of elements >= 5? */
	if (elements[4] != NULL)
	{
		char *second_operator = elements[3];
		char *third_number = elements[4];

		sprintf(result, "%s %s %s", result, third_number, second_operator);
	}

	return result;
}
