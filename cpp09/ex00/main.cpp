/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/14 13:07:13 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool valideFile(int argc, char *argv[], std::ifstream &infile)
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Error: could not open file " << "\033[0m" << std::endl;
		return false;
	}
	std::string filename = argv[1];
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "\033[31m" << "Error: could not open file " << "\033[0m" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	std::ifstream infile;
	std::ifstream exchangeRateFile;

	std::map<std::string,float> btcMap;

	if (!valideFile(argc, argv, infile))
		return 1;
	if (!parsingExchangRate(exchangeRateFile, btcMap))
		return 1;
	return 0;
}
