/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/20 18:58:43 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (argc > 2)
	{
		std::cerr << "Error: only one parameter." << std::endl;
		return 1;
	}
	Btc btc;
	try
	{
		{btc.execute(argv[1]);}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
