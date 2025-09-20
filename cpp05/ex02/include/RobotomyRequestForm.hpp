/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:45 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 19:05:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../include/AForm.hpp"

#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

	protected:
		virtual void _executeAction() const;
	
	private:
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		const std::string _target;
};

#endif
