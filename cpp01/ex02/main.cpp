/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:30:47 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/07 18:10:12 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
/* stringPTR (Pointer):
A pointer is a variable that stores the memory address of another variable.
stringPTR points to the memory location where str is stored.
To access the actual value, you use the dereference operator *.

stringREF (Reference):
A reference is an alias for another variable.
stringREF refers directly to str, so any change through stringREF also changes str.
References let you do what you would use pointers for in C — but with simpler syntax, more safety, and less risk of bugs.
*/

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable: " << &str <<std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << str <<std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
