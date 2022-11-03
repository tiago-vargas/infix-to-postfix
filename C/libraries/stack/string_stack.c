#define out /* use `out` simply to indicate that the parameter is intended to serve as a returned value */

#define STACK_CAPACITY 200

typedef struct
{
	char *elements[STACK_CAPACITY];
	int quantity;
} StringStack;

enum stack_error_codes
{
	NO_STACK_ERRORS = 0,
	POP_FROM_EMPTY_STACK_ERROR_CODE,
	PUSH_TO_FULL_STACK_ERROR_CODE
};

void push_string(char *string, StringStack *stack, out float *error_code)
{
	int index_to_put = stack->quantity;

	if (stack->quantity == STACK_CAPACITY)
	{
		*error_code = PUSH_TO_FULL_STACK_ERROR_CODE;
	}
	else
	{
		*error_code = NO_STACK_ERRORS;

		stack->elements[index_to_put] = string;
		stack->quantity++;
	}
}

char *pop_string(StringStack *stack, out float *error_code)
{
	int current_index = stack->quantity - 1;
	char *last_item = stack->elements[current_index];

	if (stack->quantity == 0)
	{
		*error_code = POP_FROM_EMPTY_STACK_ERROR_CODE;
	}
	else
	{
		*error_code = NO_STACK_ERRORS;
		stack->quantity--;
	}

	return last_item;
}
