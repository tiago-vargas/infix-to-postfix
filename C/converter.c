#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "libraries/stack/string_stack.c"

#define TAM 200

void tokenize(char string[], out char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 0; i < TAM; i++)
		tokens[i] = strtok(NULL, " ");
}

char *join_strings(StringStack *stack, char separator)
{
	char *string;
	// int total_size = (sizeof (char)) * 4;
	// char *string = malloc(total_size);

	int last_index = stack->quantity - 1;
	int penultimate_index = last_index - 1;
	for (int i = 0; i <= penultimate_index; i++)
	{
		string = strcat(string, stack->elements[i]);
		string = strcat(string, " ");
	}

	string = strcat(string, stack->elements[last_index]);
	// ["foo", "bar", "baz", "qux"]
		// ""            ++ "foo"     ++ "bar" ++ "baz" ++ "qux"
		// "foo"         ++ "bar"     ++ "baz" ++ "qux"
		// "foo bar"     ++ "baz"     ++ "qux"
		// "foo bar baz" ++ "qux"
		// "foo bar baz qux"
	return string;
}

bool is_in_list(char token, char list[], int list_length)
{
	for (int i = 0; i < list_length; i++)
		if (list[i] == token)
			return true;

	return false;
}

void move_last_element(StringStack *origin, StringStack *destination)
{
	float error_code;
	char *popped_element = pop_string(origin, &error_code);
	push_string(popped_element, destination, &error_code);
}


void move_elements_delimited_by_parentheses_between_stacks(StringStack *origin, StringStack *destination)
{
	int last_index = origin->quantity - 1;
	float error_code;

	pop_string(origin, &error_code);

	while (origin->elements[last_index] != '(')
	{
		move_last_element(origin, destination);
		last_index--;
	}

	pop_string(origin, &error_code);
}

void move_all_elements(StringStack *origin, StringStack *destination)
{
	float error_code;

	for (int i = origin->quantity - 1; i >= 0; i--)
	{
		char *symbol = pop_string(origin, &error_code);
		push_string(symbol, destination, &error_code);
	}
}

char *convert(char input[])
{
	char *tokens[TAM];
	tokenize(input, out *tokens);

	char operators[] = { '+', '-', '*', '/' };

	StringStack answer = { .quantity = 0 };
	StringStack symbols = { .quantity = 0 };
	
	char last_symbol;

	bool must_skip_iteration = false;

	for (int i = 0; i < TAM; i++)
	{
		if (must_skip_iteration)
		{
			must_skip_iteration = false;
			continue;

			char *current_token = tokens[i];

			bool current_token_is_number = !is_in_list(current_token, operators, STACK_CAPACITY) && current_token != '(' && current_token != ')';

			float error_code;

			if (current_token_is_number)
				push_string(current_token, &answer, out &error_code);
			else
				push_string(current_token, &symbols, out &error_code);

			if (strcmp(current_token, ")") == 0)
				move_elements_delimited_by_parentheses_between_stacks(&symbols, &answer);

			// NOT NICE
			if (is_in_list(current_token, operators, STACK_CAPACITY))
			{
				char *operator = current_token;
				if (strcmp(operator, "*") == 0 && strcmp(operator, "/") == 0)
				{
					char *next_token = tokens[i + 1];
					if (strcmp(next_token, "(") != 0)
					{
						char *next_number = next_token;
						push_string(next_number, &answer, out &error_code);

						pop_string(&symbols, out &error_code);
						push_string(current_token, &answer, out &error_code);
						
						must_skip_iteration = true;
					}
				}

				if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0)
				{
					int last_index = symbols.quantity - 1;
					int penultimate_index = last_index - 1;
					if (strcmp(last_symbol, "+") == 0 || strcmp(last_symbol, "-") == 0)
					{
						if (strcmp(symbols.elements[penultimate_index], "(") != 0)
						{
							char *popped_operator = pop_string(&symbols, out &error_code);

							push_string(popped_operator, &answer, out &error_code);
						}
					}
					else if (symbols.quantity > 1 && (strcmp(last_symbol, "+") == 0 || strcmp(last_symbol, "-") == 0))
					{
						char *popped_operator = pop_string(&symbols, out &error_code);

						push_string(popped_operator, &answer, &error_code);
					}		
				}
				char *
				last_operator;
				last_operator = last_symbol = tokens[i];
			}
		}
	}

	move_all_elements(&symbols, &answer);

	char *string = join_strings(&answer, ' ');

	return string;
}




/*char *convert(char input[])
{
	if (input[2] == '+')
		return "2 5 +";

	else if (input[2] == '-')
		return "2 5 -";

	else if (input[2] == '*')
		return "2 5 *";
	
	else
		return "2 5 /";
}*/
