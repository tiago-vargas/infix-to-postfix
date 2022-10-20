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


def test_single_number_with_no_operations():
	input = '5'

	output = convert(input)

	assert output == '5'
