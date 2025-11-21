/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:45:35 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 11:52:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other): _operands(other._operands)
{}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_operands = other._operands;
	}
	return *this;
}

RPN::~RPN(){}


bool RPN::_isOperator(const std::string& token) const
{
	if (token == "+" || token == "-" || token == "/" || token == "*")
		 return true ;
	else
		return false ;
}

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

bool RPN::_checkInput(const std::string& expression)
{
	if (expression.empty())
		return false;
	
	std::stringstream ss(expression);
	std::string token;
	bool hasTokens = false;
	while (ss >> token)
	{
		hasTokens = true;
		if (token.size() != 1)
			return false;
		if (std::isdigit(token[0]) == false && !_isOperator(token))
			return false;
	}
	return hasTokens;
}

bool RPN::_doCalculation(char operation)
{
	if (_operands.size() < 2)
	{
		std::cerr << "Error: operands in stack are not sufficient!" << std::endl;
		return false;
	}
	if (operation == '/' && _operands.top() == 0)
	{
		std::cerr << "Error: Division by zero is not possible!" << std::endl;
		return false;
	}
	
	int operand2 = _operands.top();
	_operands.pop();
	int operand1 = _operands.top();
	_operands.pop();
	int result = 0;
	
	switch (operation)
	{
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;
	}
	_operands.push(result);
	return true;
}

bool RPN::reversePolishNotation(const std::string& expression)
{
	if (!_checkInput(expression))
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	std::stringstream ss(expression);
	std::string token;
	
	while (ss >> token)
	{
		if (_isOperator(token))
		{
			if (!_doCalculation(token[0]))
				return false ;			
		}
		else
			_operands.push(token[0] - '0');					
	}
	if (_operands.size() == 1)
	{
		std::cout << _operands.top() << std::endl;
		return true;
	}
	else
	{
		std::cerr << "Error: improper input!" << std::endl;
		return false;		
	}
}
