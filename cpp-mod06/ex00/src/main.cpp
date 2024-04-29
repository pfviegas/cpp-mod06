// inluir header 42

# include "../include/ScalarConverter.hpp"\

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string convert = av[1];
		ScalarConverter::convert(convert);
	}
	else
	{
		std::cout << "Invalid number of arguments !!!" << std::endl;
		return (1);
	}
	return (0);
}