def unload_remaining_symbols(origin, destiny):
	for symbol in origin[::-1]:
		destiny.append(symbol)

def convert(input: str) -> str:
	tokens = input.split(' ')

	operators = ['+', '-', '*', '/']

	answer = []
	symbols = []

	answer.append(tokens[0])

	for i in range(len(tokens)):
		if tokens[i] in operators:
			operator = tokens[i]
			number_after_operator = tokens[i + 1]

			answer.append(number_after_operator)
			answer.append(operator)

	unload_remaining_symbols(symbols, answer)

	result = ' '.join(answer)

	return result

