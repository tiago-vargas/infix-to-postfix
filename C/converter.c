#include <stdio.h>
#include <stdlib.h>
#include "libraries/stack/string_stack.c"

#define SIZE 200
#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

char *get_strings_joined(StringStack *stack)
{
	char *string = malloc((sizeof (char)) * 1000);

	sprintf(string, "%s", stack->elements[0]);

	for (int i = 1; i < stack->quantity; i++)
		sprintf(string, "%s %s", string, stack->elements[i]);

	return string;
}

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
	int error_code;

	StringStack answer = { .quantity = 0 };

	char *tokens[SIZE];
	tokenize(input, out tokens);

	char *first_number = tokens[0];
	push_string(first_number, &answer, &error_code);

	int i = 1;
	while (tokens[i] != NULL)
	{
		if (is_operator(tokens[i]))
		{
			char *operator = tokens[i];
			char *number_after_operator = tokens[i + 1];

			push_string(number_after_operator, &answer, &error_code);
			push_string(operator, &answer, &error_code);
		}

		i++;
	}

	result = get_strings_joined(&answer);

	return result;
}
