// incluir header 42

#ifndef _DATA_HPP_
#define _DATA_HPP_

#include <iostream>

typedef unsigned long uintptr_t;

class Data
{
	public:
		Data();
		Data(uintptr_t const &raw);
		Data(Data const &src);
		Data &operator=(Data const &other);
		~Data();

		uintptr_t	getRaw() const;
		void		setRaw(const uintptr_t &raw);

	private:
		uintptr_t	_raw;
};

#endif