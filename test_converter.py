from converter import *


def test_simple_addition():
	input = "2 + 5"

	output = convert(input)

	assert output == '2 5 +'
