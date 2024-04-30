// incluir header 42

#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void identify(Base *p);
void identify(Base &p);
Base* generate();

#endif
