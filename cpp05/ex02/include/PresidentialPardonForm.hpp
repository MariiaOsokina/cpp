/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:21:00 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 15:17:36 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "../include/AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

	protected:
		virtual void _executeAction() const;
	
	private:
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		const std::string _target;
};

#endif
