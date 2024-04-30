// incluir header 42

#include <cstdlib>  // Para strtol, strtod, strtof
#include <cerrno>   // Para verificar erros de conversão
#include <cctype>   // Para isprint

# include "../include/ScalarConverter.hpp"

// Default Constructor
ScalarConverter::ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void) other;
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void) other;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(){}

// Auxiliar functions
static void convertDouble(const std::string& str1)
{
	float str = strtod(str1.c_str(),  NULL);
	
	if (str > 127 || str < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(str))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;

	if (str < std::numeric_limits<int>::min() || str > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(str)	 << std::endl;

	if (str1.find(".0") != std::string::npos)
	{
		std::cout << "float : "<< static_cast<float>(str) << ".0f" <<std::endl;
		std::cout << "double : " << static_cast<double>(str) << ".0"<< std::endl;
		return ;
	}

	if (str < -std::numeric_limits<float>::max() || str > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		if (str == 0)
			std::cout << "float: " << static_cast<float>(str) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(str) << "f" << std::endl;

	if (str < -std::numeric_limits<double>::max() || str > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double : " << static_cast<double>(str) <<std::endl;
}

bool isDecimalZero(float num)
{
	// Converte para int e compara com o float original
	return (static_cast<int>(num) == num);
}

static void convertFloat(const std::string& str1)
{
	float str = strtof(str1.c_str(), NULL);

	// Verificações para char
	if (str > 127 || str < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(str)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;

	// Verificações para int
	if (str < std::numeric_limits<int>::min() || str > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(str) << std::endl;

	// Verificações para float
	if (str < -std::numeric_limits<float>::max() || str > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		if (isDecimalZero(str))
			std::cout << "float: " << str << ".0f" << std::endl;
		else
			std::cout << "float: " << str << "f" << std::endl;

	// Verificações para double
	if (str < -std::numeric_limits<double>::max() || str > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(str) << std::endl;
}

static void convertInt(const std::string& str1)
{
	long int str = strtol(str1.c_str(), NULL, 10);

	// Verificações para char
	if (str > 127 || str < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(str)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;

	// Verificações para int
	if (str < std::numeric_limits<int>::min() || str > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << str << std::endl;

	// Verificações para float
	if (str < -std::numeric_limits<float>::max() || str > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(str) << "f" << std::endl;

	// Verificações para double
	if (str < -std::numeric_limits<double>::max() || str > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(str) << std::endl;
}

static void convertChar(const char *str)
{
	std::cout << "char: '" << str << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(*str) << std::endl;
	std::cout << "float: " << static_cast<float>(*str) << ".0f" <<std::endl;
	std::cout << "double: " << static_cast<double>(*str) << ".0" <<std::endl;
}

static bool	isAllDigits(const std::string &str)
{
	for (size_t i = 0 ; i < str.length() ; i++)
		if (!isdigit(str[i]))
			return (false);

	return (true);
}

static bool isInteger(const std::string &str)
{
	if ((isAllDigits(str) || (str[0]) == '-' || str[0] == '+') && isAllDigits(str.substr(1, str.length())))
		return (true);
	else
		return (false);
}

static bool isDouble(const std::string& str)
{
	char* end;
	errno = 0;
	double val = strtod(str.c_str(), &end); // Tentar converter para double
	
	(void) val;
	// Verifica se não houve caracteres após o número ou erros durante a conversão
	if (*end != '\0' || errno == ERANGE)
		return (false);
	else
		return (true);
}

static bool isFloat(const std::string& str)
{
	char* end;
	errno = 0;
	float val = strtof(str.c_str(), &end); // Tentar converter para float

	(void) val;
	if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE)
		return (false);
	else
		return (true);
}

static bool checkInfinity(const std::string& str)
{
	if(str == "inff" || str == "inf" || str == "nan" || str == "nanf" ||
		str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "-inff" || str == "+inff")
		{
			std::cout << "float: " << str << std::endl;
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl; // Remove 'f' para double
		}
		else if (str == "-inf" || str == "+inf")
		{
			std::cout << "float: " << str << "f" << std::endl; // Adiciona 'f' para float
  			std::cout << "double: " << str << std::endl;
		}
		else
		{
			std::cout << "float: nanf" << std::endl; // "nanf" para float
			std::cout << "double: nan" << std::endl; // "nan" para double
		}
		return (true);
	}
	return (false);
}

static int getType(const std::string &str)
{
	if (!isdigit(str[0]) && str.length() == 1)
		return (CHAR);
	
	if (isFloat(str))
		return (FLOAT);
	
	if (isDouble(str))
		return (DOUBLE);

	if (isInteger(str))
		return (INT);

	return (0);
}

// Member function
void ScalarConverter::convert(std::string &str)
{
	int scalarType = 0;

	if (!str.length())
	{
		std::cerr << "Error: empty string " << std::endl;
		return ;
	}
	if (checkInfinity(str))
		return ;

	scalarType = getType(str);
	switch(scalarType)
	{
		case CHAR:
			convertChar(str.c_str());
			break ;
		case INT:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		default:
			std::cerr <<"Error..." << std::endl;
	}
}