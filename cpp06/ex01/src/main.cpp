/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:42:49 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 19:52:20 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*We can safely convert a pointer to an integer and then convert it back,
without losing the original address information*/


#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

struct Data;
class Serializer;

int main()
{
	Data originalData = {"Jack", 00123, 15.05};

	std::cout << "\n\033[33m" << "Original Data:" << "\033[0m" << std::endl;
	originalData.printData();

	Data* originalPtr = &originalData;

	std::cout << "\n\033[33m"<< "Original pointer address: " << "\033[0m" << originalPtr << std::endl;

	uintptr_t serializedValue = Serializer::serialize(originalPtr);
	std::cout << "\n\033[33m"<< "Serialized value (uintptr_t): " << "\033[0m" << serializedValue << std::endl;

	Data* deserializedPtr = Serializer::deserialize(serializedValue);

	std::cout << "\n\033[33m" << "Deserialized pointer address: " << "\033[0m" << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr) {
		std::cout << "\n\033[33m"<< "Success! The deserialized pointer is equal to the original pointer." << "\033[0m" << std::endl;
	} else {
		std::cout<< "\n\033[33m" << "Failure! The pointers do not match." << "\033[0m" << std::endl;
	}
	std::cout << "\n\033[33m" << "Contents of the deserialized pointer:" << "\033[0m" << std::endl;
	deserializedPtr->printData();
	
	return 0;
}
