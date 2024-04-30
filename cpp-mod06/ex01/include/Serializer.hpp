// incluir header 42

#ifndef _SERIALIZER_HPP_
#define _SERIALIZER_HPP_

#include "Data.hpp"

class Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer();
};

#endif