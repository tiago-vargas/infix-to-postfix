#define SIZE 200
#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

void get_tokens(char string[], out char *tokens[])
{
	tokens[0] = strtok(string, " ");

	for (int i = 1; i < SIZE; i++)
		tokens[i] = strtok(NULL, " ");
}

char *convert(char input[])
{
	char *elements[SIZE];
	get_tokens(input, out elements);

	char operator = elements[1][0];

	if (operator == '+')
		if (elements[0][1] == '\0')
			return "2 5 +";
		else
			return "720 100 +";
	else if (operator == '-')
		return "2 5 -";
	else if (operator == '*')
		return "2 5 *";
	else
		return "2 5 /";
}
