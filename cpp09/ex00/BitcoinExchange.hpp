/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:54 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 00:22:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <map>        // map container
#include <iostream>   // cout, cerr
#include <fstream>    // file streams
#include <string>     // string class
#include <climits>    // int/long limits
#include <stdexcept>  // exception base classes
#include <sstream>    // string streams
#include <cstdlib>    // strtol, stdlib funcs
#include <cerrno>     // errno, ERANGE

#define CSV_FILE "data.csv"

/*std::map advantages:
- stores keys in sorted order and provides log-time lookup.
- keeps dates ("keys") automatically sorted (YYYY-MM-DD compares lexicographically);
- lower_bound() gives the first element not less than the key 
(we can quickly find the closest lower date.)
- we can step one iterator backward to get the closest earlier date*/

/*"Key" must be unique.*/

class Btc
{
	public:
		Btc();
		Btc(const Btc &other);
		Btc& operator = (const Btc &other);
		~Btc();
		typedef std::map<std::string,float>::iterator iterator;

		void execute(const std::string &inputFile);

		//exceptions
		class InvalidInput : public std::exception
		{
			private:
				std::string _message; // Store the dynamic message
			public:
				InvalidInput(const std::string& msg) : _message(msg) {}
				virtual const char *what() const throw()
				{
					return _message.c_str();
				}
			virtual ~InvalidInput() throw() {}	
		};

		class InvalidDatabase : public std::exception
		{
			private:
				std::string _message; // Store the dynamic message
			public:
				InvalidDatabase(const std::string& msg) : _message(msg) {}
				virtual const char *what() const throw()
				{
					return _message.c_str();
				}
			virtual ~InvalidDatabase() throw() {}
		};

	private:
		std::map<std::string,float> _btcMap;
	
		void _parsingExchangRate(std::string &databaseCSV);
		void _handleLine(std::string &line);
		void _calculateResult(const std::string &dateToFind, float value);;
		
		bool _checkDate(std::string &dateToFind);
		int _getMaxDays(int year, int month);
		bool _isLeap(int year);
		bool _stringToLong(const std::string &string, long &result);

};

#endif