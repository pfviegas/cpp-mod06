// incluir header 42

#include "../include/Base.hpp"

int	main()
{
	Base* ptr = generate();

	identify(ptr);	// Identify using pointer
	identify(*ptr);	// Identify using reference

	delete ptr;		// Clean up memory

	return (0);
}