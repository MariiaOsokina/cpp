/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/14 16:00:24 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool valideInputFile(int argc, char *argv[], std::ifstream &infile)
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
		std::cerr << "\033[31m" << "Error: could not open file " << filename << "\033[0m" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	std::ifstream infile;	
	if (!valideInputFile(argc, argv, infile))
		return 1;
	Btc btcTest;
	if (! btcTest.parsingExchangRate(CSV_FILE))
			return 1;
	std::string line;
	while (std::getline(infile, line))
	{
		std::string dateToFind = "2012-04-02"; // // to be added function for parsing
		float value = 1000; // to be added function for parsing
		btcTest.calculateResult(dateToFind, value);
	}	
	return 0;
}
