def convert(input: str) -> str:
	elements = input.split(' ')
	# '2 + 5 + 10'
	# ['2', '+', '5', '+', '10']

	if len(elements) == 3:
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

	elif len(elements) == 5:
		first_operator = elements[1]
		first_number = elements[0]
		second_number = elements[2]

		second_operator = elements[3]
		third_number = elements[4]

		result = first_number + ' ' + second_number + ' ' + third_number + ' ' + first_operator + ' ' + second_operator

		return result

		# if elements[1] == '+':
		# 	return result
		# elif elements[1] == '-':
		# 	return result
		# elif elements[1] == '*':
		# 	return result
		# elif elements[1] == '/':
		# 	return result
