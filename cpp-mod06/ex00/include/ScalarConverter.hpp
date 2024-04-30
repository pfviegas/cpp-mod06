// incluir header 42

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

enum scalarType
{
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
	public:
		static void convert(std::string &str);

	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter();
};

#endif
