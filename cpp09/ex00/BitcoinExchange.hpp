/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:34:54 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/14 13:00:42 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>
#include <map>

/*"Key" must be unique.
Elements are always kept in sorted order based on their keys.
It will allow you to quickly find the closest lower date.*/

bool parsingExchangRate(std::ifstream &exchangeRateFile, std::map<std::string,float> &btcMap);
