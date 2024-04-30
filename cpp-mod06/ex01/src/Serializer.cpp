// incluir header 42

#include "../include/Serializer.hpp"

// Default Constructor
Serializer::Serializer() {}

// Copy Constructor
Serializer::Serializer(Serializer const &other)
{
	*this = other;
}

// Copy assignment operator
Serializer &Serializer::operator=(Serializer const &other)
{
	(void) other;
	return (*this);
}

// Destructor
Serializer::~Serializer() {}

// Member function
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}