def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']

	result = elements[0]

	for i in range(len(elements)):
		if elements[i] in operators:
			operator = elements[i]
			number_after_operator = elements[i + 1]

			result = result + ' ' + number_after_operator + ' ' + operator

	return result
