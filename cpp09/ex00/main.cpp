/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:14:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/15 16:57:26 by mosokina         ###   ########.fr       */
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

long stringToLong(std::string string, long &result)
{
	char *endptr;
	result = strtol(string.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return false;
	return true;
}

bool isLeap(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool getMaxDays(int year, int month) {
	switch (month)
		{
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return isLeap(year) ? 29 :28;
		default:
			return 31;
	}
}

bool checkDate(std::string &dateToFind)
{
	if (dateToFind.length() != 10 || dateToFind[4] != '-' || dateToFind[4] != '-')
	{
		std::cerr << "\033[31m" << "Error: wrong format of the date " << dateToFind << "\033[0m" << std::endl;
		return false;
	}
	long year, month, date;
	if (!stringToLong(dateToFind.substr(0,4), year)
		|| !stringToLong(dateToFind.substr(5,2), month)
		|| !stringToLong(dateToFind.substr(8,2), date))
		{
			std::cerr << "\033[31m" << "Error: wrong format of the date " << dateToFind << "\033[0m" << std::endl;
			return false;
		}
	if (month > getMaxDays(year, month))
	{
		std::cerr << "\033[31m" << "Error: bag input => " << dateToFind << "\033[0m" << std::endl;
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
		std::string dateToFind = line.substr(0, 10);
		long value;
		if (checkDate(dateToFind) && stringToLong(line.substr(14, line.size()), value))
			btcTest.calculateResult(dateToFind, value);
	}	
	return 0;
}
