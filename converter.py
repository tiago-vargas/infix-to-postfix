def move_all_elements(origin: list[any], destiny: list[any]):
	for symbol in origin[::-1]:
		destiny.append(symbol)


def move_elements_delimited_by_parentheses_between_stacks(origin: list[any], destination: list[any]):
	pop_closing_parenthesis = origin.pop
	pop_closing_parenthesis()

	last_index = len(origin) - 1
	while origin[last_index] != '(':
		move_last_element(origin, destination)
		last_index -= 1

	pop_opening_parenthesis = origin.pop
	pop_opening_parenthesis()


def move_last_element(origin, destination):
    popped_element = origin.pop()
    destination.append(popped_element)


def convert(input: str) -> str:
	tokens: list[str] = input.split(' ')

	operators = ['+', '-', '*', '/']
	precedence = {'+': 1, '-': 1, '*': 2, '/': 2}

	answer: list[str] = []
	symbols: list[str] = []

	last_symbol = ''

	must_skip_iteration = False

	for i in range(len(tokens)):
		if must_skip_iteration:
			must_skip_iteration = False
			continue

		current_token = tokens[i]

		current_token_is_number = current_token not in operators + ['(', ')']

		if current_token_is_number:
			answer.append(current_token)
		else:
			symbols.append(current_token)

		if current_token == ')':
			move_elements_delimited_by_parentheses_between_stacks(origin=symbols, destination=answer)

		# NOT NICE
		if current_token in operators:
			operator = current_token

			if operator in ['*', '/']:
				next_token = tokens[i + 1]
				if next_token != '(':
					next_number = next_token
					answer.append(next_number)

					symbols.pop()
					answer.append(operator)

					must_skip_iteration = True

			if operator in ['+', '-']:
				if last_symbol in ['+', '-']:
					if symbols[-2] != '(':
						popped_operator = symbols.pop(-2)

						answer.append(popped_operator)
				elif len(symbols) > 1 and symbols[-2] in ['+', '-']:
					popped_operator = symbols.pop(-2)

					answer.append(popped_operator)

			last_operator = last_symbol = tokens[i]


	move_all_elements(symbols, answer)

	result = ' '.join(answer)

	return result
