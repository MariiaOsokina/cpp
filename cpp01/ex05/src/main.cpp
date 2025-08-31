/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:27:43 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/31 12:22:33 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

/* Here is an array of pointers to member functions to implement the Harl class.
This approach effectively replaces a chain of if/else if/else statements*/

int main()
{
	Harl harl;

	std::cout << std::endl << "[ DEBUG ] " << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "[ INFO ] " << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "[ WARNING ] " << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "[ ERROR ] " << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "[ No valid Level ]" << std::endl;
	harl.complain("ALARM");
	return 0;
}
