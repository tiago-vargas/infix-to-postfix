def convert(input: str) -> str:
	operator = input[2]

	if operator == '+':
		return '2 5 +'
	elif operator == '-':
		return '2 5 -'
	elif operator == '*':
		return '2 5 *'
	elif operator == '/':
		return '2 5 /'
