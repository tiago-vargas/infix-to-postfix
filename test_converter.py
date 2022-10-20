from converter import *


class TestSingleOperations:
	def test_single_addition(self):
		input = "2 + 5"

		output = convert(input)

		assert output == '2 5 +'


	def test_single_subtraction(self):
		input = "2 - 5"

		output = convert(input)

		assert output == '2 5 -'


	def test_single_multiplication(self):
		input = '2 * 5'

		output = convert(input)

		assert output == '2 5 *'


	def test_single_divison(self):
		input = '2 / 5'

		output = convert(input)

		assert output == '2 5 /'


def test_three_digit_numbers():
	input = '720 + 100'

	output = convert(input)

	assert output == '720 100 +'


def test_two_additions():
	input = '2 + 5 + 10'

	output = convert(input)

	assert output == '2 5 + 10 +'


# def test_multiple_additions():
# 	input = '7 + 35 + 4 + 9 + 1002'

# 	output = convert(input)

# 	assert output == '7 35 + 4 + 9 + 1002 +'
