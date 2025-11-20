/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/20 12:04:47 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdlib.h>
#include <cerrno>  // errno, ERANGE

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Error: It should be ./btc [file] " << "\033[0m" << std::endl;
		return false;
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


//at ???