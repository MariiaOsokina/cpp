/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/17 15:27:36 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc() //add default value for map???
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

/* An element in an  is stored as a std::pair<const Key, T>.
it->first Accesses the key stored in the pair pointed to by the iterator.
it->second - Accesses the mapped value stored in the pair pointed to by the iterator.*/

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
	Btc::iterator it = _btcMap.find(dateToFind);
	float rate;
	if (it != _btcMap.end())
		rate = it->second;
	else// key does not exist, seach the closest lower date 
	{
		it = _btcMap.lower_bound(dateToFind);
		rate = it->second;
	} 
	float result = value * rate;
	std::cout << dateToFind << " => " << value << " = " << result << std::endl;
}
