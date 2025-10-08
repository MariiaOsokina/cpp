/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:55:40 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/08 14:21:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <climits> // Needed for INT_MAX

/**/

class Span
{
	public:

		// Constructors / Rule of Three
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator= (const Span &other);
		~Span();
		
		// Member Functions
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
		void printStorage() const;

		// Exception Classes ---
		class FullSpanException : public std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanException : public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		std::vector<int> _storage;
		unsigned int _maxSize; 
};

#endif