/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:46:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/26 15:16:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <cstdlib> // for std::srand
#include <ctime>   // for std::time
#include <string>
#include <iostream>


// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B", or "C".
// void identify(Base& p);
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.


Base * generate(void)
{
	Base *basePtr;
// Seed the random number generator ONCE.
    std::srand(std::time(NULL));

	int randInt = rand() % 3;
	if (randInt == 0)
		basePtr = new A();
	else if (randInt == 1)
		basePtr = new B();
	else // randInt must be 2
		basePtr = new C();
	return basePtr;
}


/* Runtime Type Information (RTTI) specifically via dynamic_cast.
Attempt to cast the Base* pointer to each derived class type (A*, B*, C*) sequentially 
If dynamic_cast fails, it returns NULL*/

/*dynamic_cast only works on polymorphic types (types with at least one virtual function)*/

void identify(Base* p)
{
	std::cout << "The object pointed to by p: ";

	if (dynamic_cast<A*>(p))
		std::cout << "class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "class C" << std::endl;
	else
		std::cout << "Unindentifed" << std::endl;
}

void identify(Base& p)
{
	std::cout << "The object referenced by p: ";
	try
	{
		(void)(dynamic_cast<A&>(p));
		std::cout << "class A" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void)(dynamic_cast<B&>(p));
		std::cout << "class B" << std::endl;
		return ;
	}
	catch(...){}
		try
	{
		(void)(dynamic_cast<C&>(p));
		std::cout << "class C" << std::endl;
		return ;
	}
	catch(...)
	{
		std::cout << "Unidentified" << std::endl;
	}
}

/*No #include <typeinfo>
Using dynamic_cast correctly for both pointer and reference versions
Using catch(...) to avoid any dependency on specific exception types
No pointers used inside the reference version
C++98 syntax*/

int main()
{
    std::srand(std::time(NULL));

	Base *basePtr = generate();
	Base &baseRef = *basePtr;

	identify(basePtr);
	identify(baseRef);

	delete basePtr;
	return 0;
}
