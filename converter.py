def convert(input: str) -> str:
	elements = input.split(' ')
	# '2 + 5 + 10'
	# ['2', '+', '5', '+', '10']
	# '2 5 10 + +'

	first_operator = elements[1]
	first_number = elements[0]
	second_number = elements[2]

	result = first_number + ' ' + second_number + ' ' + first_operator

	if len(elements) == 5:
		second_operator = elements[3]
		third_number = elements[4]

		result = result + ' ' + third_number + ' ' + second_operator

	return result
