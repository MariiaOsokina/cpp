/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:54 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/14 16:00:22 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <climits>
#include <stdexcept> // For std::exception, though specific type is std::ios_base::failure

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
		bool parsingExchangRate(std::string &filename);
		void calculateResult(std::string &dateToFind, float value);
	private:
		// void parseRate();
		std::map<std::string,float> _btcMap;
};
