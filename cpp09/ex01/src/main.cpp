/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:45:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 11:55:09 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Please pass the parameter as one string" <<  std::endl;
		return 1;
	}
	
	RPN rpm;
	
	if (!rpm.reversePolishNotation(argv[1]))
		return 1;
	return 0;
}
