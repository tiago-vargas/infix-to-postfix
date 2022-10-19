from converter import *


def test_single_addition():
	input = "2 + 5"

	output = convert(input)

	assert output == '2 5 +'


def test_single_subtraction():
	input = "2 - 5"

	output = convert(input)

	assert output == '2 5 -'


def test_single_multiplication():
	input = '2 * 5'

	output = convert(input)

	assert output == '2 5 *'


def test_single_divison():
	input = '2 / 5'

	output = convert(input)

	assert output == '2 5 /'
