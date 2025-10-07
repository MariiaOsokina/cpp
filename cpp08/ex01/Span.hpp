/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:55:40 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/07 13:11:41 by mosokina         ###   ########.fr       */
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
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator= (const Span &other);
		~Span();
		

		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		
		void printStorage() const;

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