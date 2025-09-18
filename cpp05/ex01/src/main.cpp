/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/18 17:50:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

/*EXCEPTIONS: flow
1. Code inside try { ... } executes.

2. If no exception is thrown → catch is skipped.

3. If an exception is thrown (e.g., throw ...;) → execution jumps immediately to the matching catch.

4. If no matching catch is found → the program calls std::terminate() (usually crashes).
*/

void	test1(void)
{
	try
	{
		std::cout << "\033[33m" << "Test1: successful creation and printing of Form" << "\033[0m" << std::endl;
		Form testForm("Test Form", 100, 50);
		std::cout << testForm << std::endl; // Test operator<< overload
		// testForm.beSigned();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught an unexpected exception: " << e.what() << '\n';
	}
}

void	test2(void)
{
	std::cout << "\033[33m" << "Test2:  instantiate a Form with an invalid grade (low and high) "
					<< "\033[0m" << std::endl;
	try
	{
		Form f1("F1", 200, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	try
	{
		Form f2("F2", 50, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{
		Form f3("F2", -50, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	try
	{
		Form f3("F2", 50, -50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}

// void	test3(void)
// {
// 	std::cout << "\033[33m" << "Test3: grade goes out of range after its increasement / decreasement"
// 					<< "\033[0m" << std::endl;
// 	try
// 	{
// 		Bureaucrat b1("Bob", 150);
// 		std::cout << b1 << std::endl;
// 		b1.decreaseGrade();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Error: " << e.what() << '\n';
// 	}

// 	try
// 	{
// 		Bureaucrat b2("Sam", 1);
// 		std::cout << b2 << std::endl;
// 		b2.increaseGrade();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Error: " << e.what() << '\n';
// 	}
// }

void test4(void)
{
	std::cout << "\033[33m" << "Test4: Copy constructor" << "\033[0m" << std::endl;
	try
	{
		Form f1("Original", 50, 10);
		std::cout << f1 << std::endl;

		Form f2(f1);
		std::cout << "Copied form (f2): " << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught an unexpected exception: " << e.what() << '\n';
	}
}

// void test5(void)
// {
// 	std::cout << "\033[33m" << "Test5: Copy assignment operator" << "\033[0m" << std::endl;
// 	try
// 	{
// 		Bureaucrat b1("Original", 50);
// 		std::cout << b1 << std::endl;

// 		Bureaucrat b3("Another One", 100);
// 		std::cout << "Before assignment, b3 is: " << b3 << std::endl;
// 		b3 = b1;
// 		std::cout << "After assignment, b3 is: " << b3 << std::endl;
// 		std::cout << "Note: b3's name remains constant, only the grade is updated." << std::endl;
// 		std::cout << "Original bureaucrat (b1) remains unchanged: " << b1 << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "Caught an unexpected exception: " << e.what() << '\n';
// 	}
// }

int main (void)
{
	test1();
	test2();
	// test3();
	test4();
	// test5();

	return 0;
}