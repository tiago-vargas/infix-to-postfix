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

void run_all_tests()
{
	run_test(test_single_addition, "`2 + 5` should evaluate to `2 5 +`");
	run_test(test_single_subtraction, "`2 - 5` should evaluate to `2 5 -`");
}

int main()
{
	run_all_tests();
}
