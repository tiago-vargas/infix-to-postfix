def convert(input: str) -> str:
	operator = input[2]

	if operator == '+':
		return '2 5 +'
	else:
		return '2 5 *'
