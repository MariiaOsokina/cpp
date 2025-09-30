/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:46:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/30 11:39:02 by mosokina         ###   ########.fr       */
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

/*srand:
- std::time(NULL) returns the current time, which is used as the seed, 
the initial value for the random number generator. 
By using a different seed each time (like the current time), 
we can ensure that the sequence of random numbers is different each time.*/

Base * generate(void)
{
	Base *basePtr;
	std::srand(std::time(NULL));

	int randInt = rand() % 3;
	if (randInt == 0)
		basePtr = new A();
	else if (randInt == 1)
		basePtr = new B();
	else
		basePtr = new C();
	return basePtr;
}

/*DYNAMIC CAST:
- exclusively used for safe conversions within an inheritance hierarchy involving polymorphism.
- The classes must be polymorphic (i.e., the base class must have at least one virtual function)
because it uses the V-table (virtual table) to perform its runtime check.

- savety: the only cast that performs a RUNTIME (!) check. 
it fails gracefully by returning a nullptr (for pointers) 
or throwing an exception (std::bad_cast (reference)).*/

/* Subjet doesn't allow to use typeid (from <typeinfo>). 
So, we use anorther examle of Runtime Type Information (RTTI) via dynamic_cast.*/


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
