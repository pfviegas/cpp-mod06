// incluir header 42

#include "../include/Base.hpp"

// Identify the object type with a pointer
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The pointer is a type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The pointer is a type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The pointer is a type C." << std::endl;
	else
		std::cout << "Pointer is of unknown type." << std::endl;
}

// Identify the object type with a reference
void identify(Base &p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "The reference is a type A." << std::endl;
	}
	catch(const std::exception& e)
	{
		 // No action needed
	}

	try {
		B&	b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "The reference is a type B." << std::endl;
	}
	catch(const std::exception& e)
	{
		// No action needed
	}

	try {
		C&	c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "The reference is a type C." << std::endl;
	}
	catch(const std::exception& e)
	{
		// No action needed
	}
}

// creates an instance of A, B, or C randomly
Base* generate(void)
{
	static int seed = 0;
	Base* base = NULL;
	int random_value;

	// use a more precise time seed to avoid duplicate values
	seed = static_cast<int>(std::time(0));
	// increment the seed to ensure randomness.
	std::srand(seed++);
	// generates a random number between 0 and 2.
	random_value = std::rand() % 3;

	// Add messages to indicate which object is being created.
	switch (random_value) 
	{
		case 0:
			base = new A();
			std::cout << "Generated: A" << std::endl;
			break;
		case 1:
			base = new B();
			std::cout << "Generated: B" << std::endl;
			break;
		case 2:
			base = new C();
			std::cout << "Generated: C" << std::endl;
			break;
		default:
			base = NULL;	// Safety measure in case something unexpected happens.
			std::cerr << "Error: Unknown class" << std::endl;
			break;
	}

	return (base);
}
