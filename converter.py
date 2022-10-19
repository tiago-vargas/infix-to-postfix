def convert(input: str) -> str:
	elements = input.split(' ')

	operator = elements[1]
	first_number = elements[0]
	second_number = elements[2]

	result = first_number + ' ' + second_number + ' ' + operator

	if elements[1] == '+':
		return result
	elif elements[1] == '-':
		return result
	elif elements[1] == '*':
		return result
	elif elements[1] == '/':
		return result
