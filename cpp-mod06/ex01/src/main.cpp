// incluir header 42

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main()
{
	Data*		data = new Data;
	uintptr_t	raw;

	std::cout << "Pointer address: " << data << std::endl;

	raw = Serializer::serialize(data);
	std::cout << "      RAW value: " << raw << std::endl;

	data = Serializer::deserialize(raw);
	std::cout << "Pointer address: " << data << std::endl;

	delete data;

	return (0);
}