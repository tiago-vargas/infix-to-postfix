def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']
	precedence = {'+': 1, '-': 1, '*': 2, '/': 2}

	result_as_stack = []

	result_as_stack.append(elements[0])

	for i in range(len(elements)):
		if elements[i] in operators:
			operator = elements[i]
			number_after_operator = elements[i + 1]

			result_as_stack.append(number_after_operator)
			result_as_stack.append(operator)

	result = ' '.join(result_as_stack)

	return result

