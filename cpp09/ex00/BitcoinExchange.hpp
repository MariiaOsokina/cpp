/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:54 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/20 13:18:15 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <climits>
#include <stdexcept> // For std::exception, though specific type is std::ios_base::failure
#include <sstream>
#include <cstdlib> // For strtol
#include <cerrno>  // For errno and ERANGE

#define CSV_FILE "data.csv"

/*"Key" must be unique.
Elements are always kept in sorted order based on their keys.
It will allow you to quickly find the closest lower date.*/

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
		class CouldNotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Could not open file");
				}
		};

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
				
				virtual ~InvalidInput() throw() {} //??
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
				
				virtual ~InvalidDatabase() throw() {} //??
		};

		// class InvalidDateFormat : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw()
		// 		{
		// 			return ("Invalid date format. Expected 'YYYY-MM-DD'");
		// 		}
		// };

		// class InvalidColumnFormat : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw()
		// 		{
		// 			return ("Invalid column format. Expected 'date,exchange_rate'");
		// 		}
		// };

		// class InvalidDateFormat : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw()
		// 		{
		// 			return ("Invalid date format. Expected 'YYYY-MM-DD'");
		// 		}
		// };

		// class InvalidPriceFormat : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw()
		// 		{
		// 			return ("Invalid price format. Expected a number between 0.0 and 1000.0");
		// 		}
		// };
		
	private:
		void _parsingExchangRate(std::string &databaseCSV);
		void _calculateResult(std::string &dateToFind, float value);	// void parseRate();
		
		bool _checkDate(std::string &dateToFind);
		int _getMaxDays(int year, int month);
		bool _isLeap(int year);
		bool _stringToLong(const std::string string, long &result);
		void _handleLine(std::string &line);


		std::map<std::string,float> _btcMap;
};
