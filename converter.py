def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']

	if elements[1] in operators:
		operator = elements[1]
		first_number = elements[0]
		second_number = elements[2]

		result = first_number + ' ' + second_number + ' ' + operator

	if len(elements) == 5:
		if elements[3] in operators:
			operator = elements[3]
			third_number = elements[4]

			result = result + ' ' + third_number + ' ' + operator

	return result
