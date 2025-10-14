/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/14 13:16:46 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool parsingExchangRate(std::ifstream &exchangeRateFile, std::map<std::string,float> &btcMap)
{
	std::string filename = "../data.csv";
	std::string line;
	exchangeRateFile.open(filename.c_str());
	if (!exchangeRateFile.is_open())
	{
		std::cerr << "\033[31m" << "Error: could not open file " << filename << "\033[0m" << std::endl;
		return false;
	}
	while (std::getline(exchangeRateFile, line))
	{
		std::string date = "2012-04-02"; // // add function for parsing
		float exchangeRate = 4.63; // add function for parsing
		
		btcMap[date] = exchangeRate;
		std::cout << line << std::endl;
	}
	return true;
}

