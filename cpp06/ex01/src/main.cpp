/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:42:49 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 16:56:42 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*We can safely convert a pointer to an integer and then convert it back,
without losing the original address information*/


#include "../include/Serializer.hpp"
#include "../include/Data.hpp"


int main()
{
	std::cout << "\n\033[33m" <<  "TEST: Create a non-empty instance of the Data structure" << "\033[0m" << std::endl;
	// 1. Create a non-empty instance of the Data structure.
	Data original_data = {"Jack", 00123, 15.05};

	std::cout << "Original Data:" << std::endl;
	original_data.print();
	std::cout << std::endl;

	// 2. Get the original pointer to the Data object.
	Data* original_ptr = &original_data;

	std::cout << "Original pointer address: " << original_ptr << std::endl;
	std::cout << std::endl;

	// 3. Use serialize() to convert the pointer to an integer.
	uintptr_t serialized_value = Serializer::serialize(original_ptr);

	std::cout << "Serialized value (uintptr_t): " << serialized_value << std::endl;
	std::cout << std::endl;

	// 4. Use deserialize() to convert the integer back to a pointer.
	Data* deserialized_ptr = Serializer::deserialize(serialized_value);

	std::cout << "Deserialized pointer address: " << deserialized_ptr << std::endl;
	std::cout << std::endl;

	// 5. Check that the deserialized pointer is equal to the original pointer.
	if (original_ptr == deserialized_ptr) {
		std::cout << "Success! The deserialized pointer is equal to the original pointer." << std::endl;
	} else {
		std::cout << "Failure! The pointers do not match." << std::endl;
	}

	std::cout << std::endl;

	// We can also dereference the deserialized pointer to show that the data is intact.
	std::cout << "Contents of the deserialized pointer:" << std::endl;
	deserialized_ptr->print();
	
	return 0;
}
