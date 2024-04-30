// incluir header 42

#include "../include/Data.hpp"

// Default Constructor
Data::Data() : _raw(0) {}

// Parameterized Constructor
Data::Data(uintptr_t const &raw) : _raw(raw) {}

// Copy Constructor
Data::Data(Data const &other) 
{
	*this = other;
}

// Copy assignment operator
Data &	Data::operator=(Data const &other)
{
	if (this != &other)
		this->_raw = other._raw;
	return (*this);
}

// Destructor
Data::~Data() {}

// Getter
uintptr_t Data::getRaw() const
{
	return (this->_raw);
}

// Setter
void Data::setRaw(const uintptr_t &src)
{
	this->_raw = src;
}
