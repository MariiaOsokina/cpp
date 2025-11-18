/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:45:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/18 15:53:33 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream> // for stringstream

#include "../include/RPN.hpp"

/*std::stringstream belongs to the family of C++ iostreams. 
It combines three major components into one object, 
allowing you to treat a string like a file or standard input/output:

1. The Stream Buffer (std::stringbuf);
2. The Input/Output Logic (std::istream/std::ostream), Reading (>>), Writing (<<);
3. State Management - manages several flags related to the state of the I/O operations:
-e.g. eofbit (End-of-File)*/

/*Reading (>>): When you use ss >> token,
- extracts characters from the buffer until it hits whitespace;
- converts the token string into a standard C++ std::string;

It updates the internal read position pointer past the consumed token and any trailing whitespace.*/
int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Please pass the parameter as one string" <<  std::endl;
		return 1;
	}
	class RPN rpm;
	
	if (!rpm.reversePolishNotation(argv[1]))
		return 1; // Returns non-zero status (failure)
	return 0;	
	
}
/*
	check than only one argument passed
	
	parsing of the string:
	1. split to words array of words, c++ style
	2. check each word:
		a. if is it digit std::isdigit(c - '0'), convert to int from char;
		b. if else is not it + - / * then break and exit with error status;
	
	loop array of words:
	1. till operator(+ - / *) all integers till operator(+ - / *) save in std::stack<deque> ;
	2. if operator, pop two integers from stack:
		a. check if less than two operands in stack then "Error"
		b. check if division and 2d operand (1st from stack) zero then "Error";
		b. do calculation: if "+" do addition; if "-" do substruction of them; if "*" do multiplucation of them;
		if "/" do division of them
		3. push the result to the stack
	
	after loop check if stack/size() == 1, else "Error";
	
	pop the result (top of stack) and print it;
	
	
	return 0;
}
	*/