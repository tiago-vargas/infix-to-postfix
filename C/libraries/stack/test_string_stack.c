#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "string_stack.c"
#include "../test_framework/test_framework.c"

#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

bool test_pushing_one_item_to_stack(out float *error_code)
{
	StringStack stack = { .quantity = 0 };

	push_string("home", &stack, out error_code);

	return strcmp(stack.elements[0], "home") == 0;
}

void run_all_tests()
{
	printf("-- STRING STACK TEST RESULTS --\n");

	run_test(test_pushing_one_item_to_stack,
	         "pushing 'home' to empty stack should make its elements be [ 'home', ... ]");
}

void main()
{
	run_all_tests();
}
