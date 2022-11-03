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

bool test_pushing_multiple_items(out float *error_code)
{
	StringStack stack = { .quantity = 0 };

	push_string("home", &stack, out error_code);
	push_string("office", &stack, out error_code);

	return strcmp(stack.elements[0], "home") == 0
	       && strcmp(stack.elements[1], "office") == 0;
}

bool test_incrementing_stack_on_push(out float *error_code)
{
	StringStack stack = { .quantity = 0 };

	push_string("home", &stack, out error_code);

	return stack.quantity == 1;
}

bool test_popping_from_stack(out float *error_code)
{
	StringStack stack = { .quantity = 0 };
	stack.elements[0] = "home";
	stack.elements[1] = "office";
	stack.quantity = 2;

	char *last_string = pop_string(&stack, out error_code);

	return strcmp(last_string, "office") == 0;
}

bool test_decrementing_stack_on_pop(out float *error_code)
{
	StringStack stack = { .quantity = 0 };
	stack.elements[0] = "home";
	stack.elements[1] = "office";
	stack.quantity = 2;

	pop_string(&stack, out error_code);

	return stack.quantity == 1;
}

bool test_popping_from_empty_stack_to_have_no_effect(out float *error_code)
{
	StringStack stack = { .quantity = 0 };

	pop_string(&stack, out error_code);

	return stack.quantity == 0;
}

bool test_pushing_to_full_stack_to_have_no_effect()
{
	StringStack stack = { .quantity = STACK_CAPACITY };

	float error_code;

	push_string("home", &stack, &error_code);

	return stack.quantity == STACK_CAPACITY;
}

bool test_popping_from_empty_stack_error(out float *error_code)
{
	StringStack stack = { .quantity = 0 };

	pop_string(&stack, out error_code);

	return *error_code == POP_FROM_EMPTY_STACK_ERROR_CODE;
}

void run_all_tests()
{
	printf("-- STRING STACK TEST RESULTS --\n");

	run_test(test_pushing_one_item_to_stack,
	         "pushing 'home' to empty stack should make its elements be [ 'home', ... ]");
	run_test(test_pushing_multiple_items,
	         "pushing 'home', 'office' to empty stack should make its elements be [ 'home', 'office', ... ]");
	run_test(test_incrementing_stack_on_push,
	         "pushing to empty stack should make its quantity be 1");

	run_test(test_popping_from_stack,
	         "popping from [ 'home, 'office', ... ] should return 'office'");
	run_test(test_decrementing_stack_on_pop,
	         "popping from stack of 2 elements should make its quantity be 1");

	run_test(test_popping_from_empty_stack_to_have_no_effect,
	         "popping from empty stack should make its quantity still be 0");
	run_test(test_pushing_to_full_stack_to_have_no_effect,
	         "pushing to full stack should make its quantity still be STACK_CAPACITY");

	run_test(test_popping_from_empty_stack_error,
	         "popping from empty stack should return error code of POP_FROM_EMPTY_STACK_ERROR_CODE");
}

void main()
{
	run_all_tests();
}
