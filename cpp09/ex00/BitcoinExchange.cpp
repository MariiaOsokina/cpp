/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/15 12:04:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc()
{}

Btc::Btc(const Btc &other): _btcMap(other._btcMap)
{}

Btc& Btc::operator = (const Btc &other)
{
	if (this != &other)
		this->_btcMap = other._btcMap;
	return (*this);
}

Btc::~Btc()
{}

bool Btc::parsingExchangRate(std::string &filename)
{
	std::ifstream exchangeRateFile(filename.c_str());
	if (!exchangeRateFile.is_open())
	{
		std::cerr << "\033[31m" << "Error: could not open file " << filename << "\033[0m" << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(exchangeRateFile, line))
	{
		std::string date = "2012-04-02"; // // add function for parsing
		float exchangeRate = 1.1; // add function for parsing
		
		_btcMap[date] = exchangeRate;
		std::cout << line << std::endl;
	}
	return true;
}

void Btc::calculateResult(std::string &dateToFind, float value)
{
	if (value < 0)
	{
		std::cerr << "\033[31m" << "Error: not a positive number." << "\033[0m" << std::endl;
		return ;
	}
	if (value > 1000)
	{
		std::cerr << "\033[31m" << "Error: too large number." << "\033[0m" << std::endl;
		return ;
	}
	std::map<std::string,float>::iterator it;

	float result = value *_btcMap[dateToFind];
	std::cout << dateToFind << " => " << value << " = " << result << std::endl;
}

