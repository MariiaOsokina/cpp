/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/29 19:50:22 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.h"

int main(void)
{
    ClapTrap ctr0;
    ClapTrap ctr1("first");
    ClapTrap ctr2("second");
    ClapTrap ctr3("third");
    ClapTrap ctr4(ctr3);
    
    ctr3 = ctr2;
    ctr1.attack("clap trap second");
    ctr2.takeDamage(2);
    ctr3.beRepaired(3);
    
    return (0);
}