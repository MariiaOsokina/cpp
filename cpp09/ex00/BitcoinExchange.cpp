/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 00:17:06 by mosokina         ###   ########.fr       */
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

// /* An element in an  is stored as a std::pair<const Key, T>.
// it->first Accesses the key stored in the pair pointed to by the iterator.
// it->second - Accesses the mapped value stored in the pair pointed to by the iterator.*/
void Btc::_calculateResult(const std::string &dateToFind, float value)
{
	Btc::iterator it = _btcMap.lower_bound(dateToFind);
	float rate;

	if (it != _btcMap.end() && it->first == dateToFind)
		rate = it->second; //exact date match found
	else
	{
		if (it != _btcMap.begin())
		{
			it--;
			rate = it->second;
		}
		else
		{
			std::cerr << "Error: Date " << dateToFind << " is before the first exchange rate date."  << std::endl;
			return;
		}
	}
	
	float result = value * rate;
	std::cout << dateToFind << " => " << value << " = " << result << std::endl;
}

void Btc::_handleLine(std::string &line)
{
	size_t delimiterPos = line.find(" | ");
	
	if (delimiterPos == std::string::npos || line.length() < 14)
		throw InvalidInput("Error: bad input => " + line);
	std::string dateToFind = line.substr(0, delimiterPos);
	if (!_checkDate(dateToFind))
	{
		std::string errorMsg = "Error: bad input => " + line;
		throw InvalidInput(errorMsg);
	}

	std::string valueStr = line.substr(delimiterPos + 3);
	float value;
	std::istringstream iss(valueStr);

	if (!(iss >> value) || !iss.eof())
		throw InvalidInput("Error: bad input => " + line);
	if (value < 0.0f)
		throw InvalidInput("Error: not a positive number.");
	if (value > 1000.0f) 
		throw InvalidInput("Error: too large a number.");
	_calculateResult(dateToFind, value);
}

bool Btc::_stringToLong(const std::string &string, long &result)
{
	char *endptr;
	const char* startptr = string.c_str();
	errno = 0;
	result = strtol(startptr, &endptr, 10);
	if (errno == ERANGE) // check overflow/underflow
	{
		return false;
	}	
	if (endptr == startptr) //empty/non numeric
	{
		return false;
	}
	if (*endptr != '\0') // trailing junk
	{
		return false;
	}	
	return true;
}

bool Btc::_isLeap(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

int Btc::_getMaxDays(int year, int month) {
	switch (month)
		{
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return _isLeap(year) ? 29 :28;
		default:
			return 31;
	}
}

bool Btc::_checkDate(std::string &dateToFind)
{
	if (dateToFind.length() != 10 || dateToFind[4] != '-' || dateToFind[7] != '-')
			return false;
	long year, month, day;
	if (!_stringToLong(dateToFind.substr(0,4), year)
		|| !_stringToLong(dateToFind.substr(5,2), month)
		|| !_stringToLong(dateToFind.substr(8,2), day))
			return false;

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > _getMaxDays(year, month))
		return false;
	return true;
}

void Btc::_parsingExchangRate(std::string &databaseCSV)
{
	std::ifstream exchangeRateFile(databaseCSV.c_str());
	if (!exchangeRateFile.is_open())
		throw InvalidDatabase("Database error: could not open CSV file.");

	std::string line;
	if (!std::getline(exchangeRateFile, line)) // skip the header and check "is empty"
		throw InvalidDatabase("Database error: file is empty or missing header.");
	std::string dateStr;
	std::string rateStr;
	float exchangeRate;
	size_t delimiterInx;

	while (std::getline(exchangeRateFile, line))
	{
		delimiterInx = line.find(',');
		if (delimiterInx == std::string::npos)
			throw InvalidDatabase("Database error: missing delimiter.");
		dateStr = line.substr(0, delimiterInx);
		rateStr = line.substr(delimiterInx + 1);
		if (!_checkDate(dateStr))
				throw InvalidDatabase("Database error: invalid date format.");
		std::istringstream iss(rateStr);
		if (!(iss >> exchangeRate) || !iss.eof())
			throw InvalidDatabase("Database error: invalid exchange rate value.");
		if (exchangeRate < 0)
			throw InvalidDatabase("Database error: negative exchange rate.");
		_btcMap[dateStr] = exchangeRate;
	}
}

void Btc::execute(const std::string &inputFile)
{
	std::ifstream infile;
	infile.open(inputFile.c_str());
	if (!infile.is_open())
		throw InvalidInput("Error: could not open file.");

	std::string databaseCSV = CSV_FILE;
	_parsingExchangRate(databaseCSV);

	std::string line;
	if (!std::getline(infile, line))
		throw InvalidDatabase("Error: empty file");
	if (line != "date | value")
		_handleLine(line);
	while (std::getline(infile, line))
	{
		try
		{
			_handleLine(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
