/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:20:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:03:43 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


// In your main function, create and fill an array of Animal objects. Half of it will
// be Dog objects and the other half will be Cat objects. At the end of your program
// execution, loop over this array and delete every Animal. You must delete directly dogs
// and cats as Animals. The appropriate destructors must be called in the expected order.

void additionalTests()
{
	std::cout << std::endl << "TEST COPY CONSTRUCTOR:" << std::endl;
	Cat myCat;
	Cat catCopy(myCat);

	std::cout << std::endl << "TEST COPY ASSIGNMENT OPERATOR:" << std::endl;
	Cat catAnother;
	catAnother = myCat;

	std::cout << std::endl << "TEST IDEAS:" << std::endl;
	int i = 1;
	int outRange = 101;
	const std::string new_idea = "Meow! Meow! Meow!";
	
	std::cout << "Cat's idea number " << i << " is " << myCat.getCatIdea(i) << std::endl;
	myCat.setCatIdea(i, new_idea);
	std::cout << "Cat's idea number " << i << " is " << myCat.getCatIdea(i) << std::endl;
	
	myCat.setCatIdea(outRange, new_idea);
	// std::cout << "Cat's idea number " << outRange << " is " << myCat.getCatIdea(outRange) << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "CREATING AN ARRAY OF ANIMALS:" << std::endl;
	Animal *Animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			Animal[i] = new Cat();
		else
			Animal[i] = new Dog();
	}
	
	std::cout << std::endl << "DELETING AN ARRAY OF ANIMALS" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete Animal[i];
	}

	additionalTests();

	return (0);
}
