/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:20:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:36:47 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator = (const Brain& other);
		~Brain();
		void setIdea(unsigned int i, const std::string& idea);
		const std::string& getIdea(unsigned int i) const;
		static const unsigned int numberOfIdeas = 100;
		void printIdeas() const;

	private:
		std::string _ideas[100];
};

#endif
