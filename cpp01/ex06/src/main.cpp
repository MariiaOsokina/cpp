/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:27:43 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/14 22:14:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char** argv)
{
	Harl harl;

	(void)argc;
	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "Only one message, please" << std::endl;
	return 0;
}
