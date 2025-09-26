/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:57:53 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 19:44:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

void Data::printData()
{
	std::cout << "Data address: " << this << std::endl;
	std::cout << "Name:\t" << name << std::endl;
	std::cout << "ID:\t" << id << std::endl;
	std::cout << "Score:\t" << score << std::endl;
}
