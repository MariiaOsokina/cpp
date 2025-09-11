/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:20:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 14:47:53 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

/* The virtual keyword enables runtime polymorphism, 
which allows you to call a derived class's function through a base class pointer.
The compiler uses a virtual table (v-table) to look up the correct function at runtime.
*/

/*demonstrate runtime polymorphism in C++ using base class pointers.*/

void testPolymorphism(void)
{
	std::cout << std::endl << "TEST: Testing Polymorphism with Pointers" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
}

/*WrongAnimal exercise shows STATIC DISPATCH, 
where the compiler decides which function to call based on the pointer's type, 
not the object's actual type.
makeSound() function is NOT (!) virtual, the compiler will call WrongAnimal::makeSound(), so
Cat object will make an Animal sound.
*/

void myTest1(void)
{
	std::cout << std::endl << "TEST1: Creation of objects and functions:" << std::endl;

	Animal defaultAnimal;
	std::cout << "Type:" << defaultAnimal.getType() << std::endl;
	defaultAnimal.makeSound();

	Dog myDog;
	std::cout << "Type:" << myDog.getType() << std::endl;
	myDog.makeSound();
}

void myTest2(void)
{
	std::cout << std::endl << "TEST2: Testing Copy Constructor and Assignment:" << std::endl;

	Dog originalDog;
	Dog copiedDog = originalDog;
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
	std::cout << "Assigned Dog type: " << assignedDog.getType() << std::endl;
}

void testWrongBehaviour(void) {
	std::cout << std::endl << "TEST: Testing Wrong Behaviour" << std::endl;

	WrongCat myWrongCat;
	const WrongAnimal* wrongAnimalPtr = &myWrongCat;

	std::cout << "Testing wrong makeSound() behavior:" << std::endl;
	wrongAnimalPtr->makeSound();

	std::cout << "Testing regular behavior:" << std::endl;
	myWrongCat.makeSound();
}

int main(void)
{
	testPolymorphism();
	testWrongBehaviour();
	myTest1();
	myTest2();
	return (0);
}