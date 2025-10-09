/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:35:44 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/09 11:00:32 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

/*std::stack offers a very limited set of member functions:
push(): Adds an element to the top of the stack.
pop(): Removes the element from the top of the stack.
top(): Returns a reference to the element at the top of the stack (without removing it).
empty(): Checks if the stack is empty.
size(): Returns the number of elements in the stack.*/

void additionalTests(const MutantStack<int>& mstack)
{
	std::cout << "\n\033[33m" << "Additional tests:" << "\033[0m" << std::endl;

	MutantStack<int> mstack_copy(mstack);
	std::cout << "\nTest Copy Constructor (top of copy): " << mstack_copy.top() << std::endl;

	MutantStack<int> mstack_assigned;
	mstack_assigned = mstack;
	std::cout << "Test Copy Assignment (top of assigned): " << mstack_assigned.top() << std::endl;

	MutantStack<int> empty_stack;
	if (empty_stack.begin() == empty_stack.end())
		std::cout << "\nTest Empty Stack Iterators: OK" << std::endl;
	else
		std::cout << "\nTest Empty Stack Iterators: FAIL" << std::endl;
}

int main()
{
	std::cout << "\n\033[33m" << "Results with MutantStack<int>:" << "\033[0m" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n\033[33m" << "Results with std::list<int>: " << "\033[0m" << std::endl;

	std::list<int> listCont;
	listCont.push_back(5);
	listCont.push_back(17);
	std::cout << listCont.back() << std::endl;
	listCont.pop_back();
	std::cout << listCont.size() << std::endl;
	listCont.push_back(3);
	listCont.push_back(5);
	listCont.push_back(737);
	listCont.push_back(0);
	std::list<int>::iterator itList = listCont.begin();
	std::list<int>::iterator itListE = listCont.end();

	while (itList != itListE)
	{
		std::cout << *itList << std::endl;
		++itList;
	}

	additionalTests(mstack);
	return 0;
}
