/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:45:31 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/18 15:39:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream> // for stringstream
#include <stack>

/*Since the RPN algorithm relies on LIFO (Last-In, First-Out) behavior, 
the std::stack is the ideal and most appropriate container.*/

/*the std::stack is a container adaptor, 
meaning it uses an underlying container to perform its LIFO operations. 

std::stack<int> (which defaults to using std::deque<int>) (Double-Ended Queue).*/

/*std::deque (Double-Ended Queue) is a powerful container that is often not explicitly forbidden in these types of constraints 
and is perfectly suited for stack operations (push/pop from one end).*/

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		bool reversePolishNotation(const std::string& expression);
	private:

	bool _checkInput(const std::string& expression);
	bool _doCalculation(char operation);
	bool _isOperator(const std::string& token) const;
	std::stack<int> _operands;


};