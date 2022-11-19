#include <stdbool.h>
#include <string.h>
#include "libraries/test_framework/test_framework.c"
#include "converter.c"

bool test_single_addition()
{
	char input[] = "2 + 5";

	char *output = convert(input);

	return strcmp(output, "2 5 +") == 0;
}

bool test_single_subtraction()
{
	char input[] = "2 - 5";

	char *output = convert(input);

	return strcmp(output, "2 5 -") == 0;
}

bool test_single_multiplication()
{
	char input[] = "2 * 5";

	char *output = convert(input);

	return strcmp(output, "2 5 *") == 0;
}

bool test_single_division()
{
	char input[] = "2 / 5";

	char *output = convert(input);

	return strcmp(output, "2 5 /") == 0;
}

bool test_three_digit_numbers()
{
	char input[] = "720 + 100";

	char *output = convert(input);

	return strcmp(output, "720 100 +") == 0;
}

bool test_float_numbers()
{
	char input[] = "5.6 / 9.8";

	char *output = convert(input);

	return strcmp(output, "5.6 9.8 /") == 0;
}

bool test_two_additions()
{
	char input[] = "2 + 5 + 10";

	char *output = convert(input);

	return strcmp(output, "2 5 + 10 +") == 0;
}

bool test_multiple_additions()
{
	char input[] = "7 + 35 + 4 + 9 + 1002";

	char *output = convert(input);

	return strcmp(output, "7 35 + 4 + 9 + 1002 +") == 0;
}

bool test_multiple_additions_and_subtractions()
{
	char input[] = "7 + 35 - 4 - 9 + 1002";

	char *output = convert(input);

	return strcmp(output, "7 35 + 4 - 9 - 1002 +") == 0;
}

bool test_single_number_with_no_operations()
{
	char input[] = "7";

	char *output = convert(input);

	return strcmp(output, "7") == 0;
}

bool test_operator_precedence()
{
	char input[] = "2 + 5 * 4 + 1";

	char *output = convert(input);

	return strcmp(output, "2 5 4 * + 1 + ") == 0;
}

bool test_parentheses_with_no_operators()
{
	char input[] = "( 5 )";

	char *output = convert(input);

	return strcmp(output, "( 5 )") == 0;
}

bool test_complicated_expression()
{
	char input[] = "( 1 + ( 2 + 3 * 4 * 5 ) ) / ( 10 + 3 )";

	char *output = convert(input);

	return strcmp(output, "1 2 3 4 * 5 * + + 10 3 + /") ==0;
}

void run_all_tests()
{
	run_test(test_single_addition, "`2 + 5` should evaluate to `2 5 +`");
	run_test(test_single_subtraction, "`2 - 5` should evaluate to `2 5 -`");
	run_test(test_single_multiplication, "`2 * 5` should evaluate to `2 5 *`");
	run_test(test_single_division, "`2 / 5` should evaluate to `2 5 /`");

	run_test(test_three_digit_numbers, "`720 + 100` should evaluate to `720 100 +`");
	run_test(test_float_numbers, "`5.6 / 9.8` should evaluate to `5.6 9.8 /`");

	run_test(test_two_additions, "`2 + 5 + 10` should evaluate to `2 5 + 10 +`");
	run_test(test_multiple_additions, "`7 + 35 + 4 + 9 + 1002` should evaluate to `7 35 + 4 + 9 + 1002 +`");
	run_test(test_multiple_additions_and_subtractions, "`7 + 35 - 4 - 9 + 1002` should evaluate to `7 35 + 4 - 9 - 1002 +`");

	run_test(test_single_number_with_no_operations, "`7` should evaluate to `7`");
	run_test(test_operator_precedence, "`2 + 5 * 4 + 1` should evaluate to `2 5 4 * + 1 +`");
	run_test(test_parentheses_with_no_operators, "`( 5 )` should evaluate to `5`");

	run_test(test_complicated_expression, "`( 1 + ( 2 + 3 * 4 * 5 ) ) / ( 10 + 3 )` should evaluate to `1 2 3 4 * 5 * + + 10 3 + /`");
}

int main()
{
	run_all_tests();
}
