/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:20:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 23:25:58 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/AAnimal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

/*ex 00 demonstrates runtime polymorphism in C++ using base class pointers.*/

void testPolymorphism(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST: Testing Polymorphism with Pointers" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete j;
	delete i;
}

void myTest1(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST1: Creation of objects and functions:" << std::endl;

	Dog myDog;
	std::cout << "Type:" << myDog.getType() << std::endl;
	myDog.makeSound();
}

void myTest2(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST2: Testing Copy Constructor and Assignment:" << std::endl;

	Dog originalDog;
	Dog copiedDog = originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
	std::cout << "Assigned Dog type: " << assignedDog.getType() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

int main(void)
{
	testPolymorphism();
	myTest1();
	myTest2();
	return (0);
}
