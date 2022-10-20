def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']

	result = elements[0]

	if len(elements) > 1:
		if elements[1] in operators:
			operator = elements[1]
			number_after_operator = elements[2]

			result = result + ' ' + number_after_operator + ' ' + operator

	if len(elements) == 5:
		if elements[3] in operators:
			operator = elements[3]
			number_after_operator = elements[4]

			result = result + ' ' + number_after_operator + ' ' + operator

	return result
