/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:06 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include <string>
#include <iostream>

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		virtual void makeSound() const;
		void setCatIdea(unsigned int i, const std::string &str);
		const std::string&  getCatIdea(unsigned int i) const;

	private:
		Brain *_attribute;
};

#endif
