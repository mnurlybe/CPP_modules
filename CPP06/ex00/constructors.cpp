#include "conversion.hpp"

ScalarConverter::ScalarConverter () {}

ScalarConverter::ScalarConverter(const ScalarConverter& source)
{
	*this = source;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source)
{
	if (this == &source)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter () {}
