/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:57:53 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 16:58:47 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

void Data::print()
{
	std::cout << "Data instance at address: " << this << std::endl;
	std::cout << "  Name: " << name << std::endl;
	std::cout << "  ID: " << id << std::endl;
	std::cout << "  Score: " << score << std::endl;
}

