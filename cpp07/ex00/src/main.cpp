/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:28:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/29 14:42:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Templates.hpp"

#include <iostream>

void	testSwap()
{
	std::cout << "\n\033[33m" << "SWAP TEST:" << "\033[0m" << std::endl;

	std::cout << "Intergers" << std::endl;
	int i1 = 42;
	int i2 = -42;
	std::cout << "Before Swap: i1=" << i1 << ", i2=" << i2 << std::endl;
	swap(i1, i2);
	std::cout << "After Swap: i1=" << i1 << ", i2=" << i2 << std::endl;


	std::cout << "Doubles" << std::endl;
	double d1 = 42.4242424;
	double d2 = -42.424242;
	std::cout << "Before Swap: d1=" << d1 << ", d2=" << d2 << std::endl;
	swap(d1, d2);
	std::cout << "After Swap: d1=" << d1 << ", d2=" << d2 << std::endl;


	std::cout << "Floats" << std::endl;
	float f1 = 42.42f;
	float f2 = -42.42f;
	std::cout << "Before Swap: f1=" << f1 << ", f2=" << f2 << std::endl;
	swap(f1, f2);
	std::cout << "After Swap: f1=" << f1 << ", f2=" << f2 << std::endl;

	std::cout << "Chars" << std::endl;
	char c1 = 'A';
	char c2 = 'Z';
	std::cout << "Before Swap: c1=" << c1 << ", c2=" << c2 << std::endl;
	swap(c1, c2);
	std::cout << "After Swap: c1=" << c1 << ", c2=" << c2 << std::endl;
}


void	testMaxMin()
{
	std::cout << "\n\033[33m" << "MAX / MIN TEST:" << "\033[0m" << std::endl;

	std::cout << "Intergers" << std::endl;
	int i1 = 42;
	int i2 = -42;
	std::cout << "Value i1=" << i1 << ", i2=" << i2 << std::endl;
	std::cout << "Max value:" << max(i1, i2) << std::endl;
	std::cout << "Min value:" << min(i1, i2) << std::endl;


	std::cout << "Doubles" << std::endl;
	double d1 = 42.4242424;
	double d2 = -42.424242;
	std::cout << "Value d1=" << d1 << ", d2=" << d2 << std::endl;
	std::cout << "Max value:" << max(d1, d2) << std::endl;
	std::cout << "Min value:" << min(d1, d2) << std::endl;


	std::cout << "Floats" << std::endl;
	float f1 = 42.42f;
	float f2 = -42.42f;
	std::cout << "Value f1=" << f1 << ", f2=" << f2 << std::endl;
	std::cout << "Max value:" << max(f1, f2) << std::endl;
	std::cout << "Min value:" << min(f1, f2) << std::endl;

	std::cout << "Chars" << std::endl;
	char c1 = 'A';
	char c2 = 'Z';
	std::cout << "Value c1=" << c1 << ", c2=" << c2 << std::endl;
	std::cout << "Max value:" << max(c1, c2) << std::endl;
	std::cout << "Min value:" << min(c1, c2) << std::endl;
}

int main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	
	std::cout << "\n\033[33m" << "More tests:" << "\033[0m" << std::endl;

	
	testSwap();
	testMaxMin();
	
	return 0;
}
