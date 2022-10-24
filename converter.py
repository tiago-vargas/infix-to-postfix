def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']
	precedence = {'+': 1, '-': 1, '*': 2, '/': 2}

	symbols = []
	answer = []

	last_symbol = ''

	for i in range(len(elements)):
		current_element = elements[i]
		is_number = current_element not in operators
		if is_number and last_symbol in ['*', '/']:
			continue

		if is_number:
			answer.append(current_element)

		is_operator = current_element in operators
		if is_operator:
			operator = current_element
			symbols.append(operator)

			if operator in ['*', '/']:
				next_number = elements[i + 1]
				answer.append(next_number)

				symbols.pop()
				answer.append(operator)

			if operator in ['+', '-']:
				if last_symbol in ['+', '-']:
					popped_operator = symbols.pop(-2)

					answer.append(popped_operator)
				elif len(symbols) > 1 and symbols[-2] in ['+', '-']:
					popped_operator = symbols.pop(-2)

					answer.append(popped_operator)

			last_symbol = elements[i]



	for symbol in symbols[::-1]:
		answer.append(symbol)

	result = ' '.join(answer)

	return result
