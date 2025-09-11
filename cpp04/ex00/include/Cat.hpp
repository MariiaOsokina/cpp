/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:06 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 12:52:26 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const std::string &name);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		virtual void makeSound() const;
};
