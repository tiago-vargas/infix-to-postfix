def unload_remaining_symbols(origin, destiny):
	for symbol in origin[::-1]:
		destiny.append(symbol)


def pop_everything_between_parentheses_and_insert_in_other_stack(origin, destination):
	origin.pop() # )

	i = len(origin) - 1
	while origin[i] != '(':
		popped_element = origin.pop()
		destination.append(popped_element)
		i -= 1

	origin.pop() # (


def convert(input: str) -> str:
	elements = input.split(' ')

	operators = ['+', '-', '*', '/']

	answer = []
	symbols = []

	last_symbol = ''

	for i in range(len(elements)):
		current_element = elements[i]

		if current_element == '(':
			symbols.append(current_element)

		if current_element == ')':
			symbols.append(current_element)

			pop_everything_between_parentheses_and_insert_in_other_stack(origin=symbols, destination=answer)


		is_number = current_element not in operators and current_element not in ['(', ')']
		if is_number and last_symbol in ['*', '/']:
			if len(elements) > 0:
				if elements[i - 1] != '(':
					continue

		if is_number:
			answer.append(current_element)

		is_operator = current_element in operators
		if is_operator:
			operator = current_element
			symbols.append(operator)

			if operator in ['*', '/']:
				if elements[i + 1] != '(':
					next_number = elements[i + 1]
					answer.append(next_number)

					symbols.pop()
					answer.append(operator)

			if operator in ['+', '-']:
				if last_symbol in ['+', '-']:
					if symbols[-2] != '(':
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

