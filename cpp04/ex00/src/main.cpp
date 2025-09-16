/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:20:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 22:52:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

/*ex 00 demonstrates runtime polymorphism in C++ using base class pointers.*/

void testPolymorphism(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST: Testing Polymorphism with Pointers\n" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete j;
	delete i;
	delete meta;
	std::cout << "-----------------------------------" << std::endl;
}

/*WrongAnimal exercise shows STATIC DISPATCH, 
where the compiler decides which function to call based on the pointer's type, 
not the object's actual type.
makeSound() function is NOT (!) virtual, the compiler will call WrongAnimal::makeSound(), so
Cat object will make an Animal sound.

The compiler only calls the WrongAnimal destructor, not the WrongCat destructor.*/

void testWrongBehaviour(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST: Testing Wrong Behaviour\n" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << "!!!!Here is WRONG (!) makeSound() behavior:" << std::endl;
	i->makeSound();
	std::cout << "!!!!Here is WRONG deleting of objects (watch destructors):" << std::endl; 
	delete i;
	delete meta;
	std::cout << "-----------------------------------" << std::endl;
}

void myTest1(void)
{
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "TEST1: Creation of objects and functions:" << std::endl;

	Animal defaultAnimal;
	std::cout << "Type:" << defaultAnimal.getType() << std::endl;
	defaultAnimal.makeSound();
	std::cout << "-----------------------------------" << std::endl;
	Dog myDog;
	std::cout << "Type:" << myDog.getType() << std::endl;
	myDog.makeSound();
	std::cout << "-----------------------------------" << std::endl;
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
	testWrongBehaviour();
	myTest1();
	myTest2();
	return (0);
}