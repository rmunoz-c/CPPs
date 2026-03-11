/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 17:03:47 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 17:03:47 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n=== TEST 1: Basic serialization ===" << std::endl;
	{
		Data original;
		original.id = 42;
		original.name = "Alice";
		original.value = 3.14;

		std::cout << "\n→ Original object:" << std::endl;
		std::cout << "   Address: " << &original << std::endl;
		std::cout << "   id:      " << original.id << std::endl;
		std::cout << "   name:    " << original.name << std::endl;
		std::cout << "   value:   " << original.value << std::endl;

		Data *ptr = &original;
		uintptr_t serialized = Serializer::serialize(ptr);

		std::cout << "\n→ Serialized:" << std::endl;
		std::cout << "   Raw value: " << serialized << std::endl;

		Data *restored = Serializer::deserialize(serialized);

		std::cout << "\n→ Deserialized object:" << std::endl;
		std::cout << "   Address: " << restored << std::endl;
		std::cout << "   id:      " << restored->id << std::endl;
		std::cout << "   name:    " << restored->name << std::endl;
		std::cout << "   value:   " << restored->value << std::endl;

		std::cout << "\n→ Verification:" << std::endl;
		std::cout << "   Pointers match? " << (ptr == restored ? "YES" : "NO") << std::endl;
		std::cout << "   Data intact? " << (restored->id == 42
			&& restored->name == "Alice"
			&& restored->value == 3.14 ? "YES" : "NO") << std::endl;
	}

	std::cout << "\n=== TEST 2: Multiple objects ===" << std::endl;
	{
		Data obj1, obj2, obj3;

		obj1.id = 1;
		obj1.name = "First";
		obj1.value = 1.1;

		obj2.id = 2;
		obj2.name = "Second";
		obj2.value = 2.2;

		obj3.id = 3;
		obj3.name = "Third";
		obj3.value = 3.3;

		std::cout << "\n→ Serializing 3 objects..." << std::endl;
		uintptr_t s1 = Serializer::serialize(&obj1);
		uintptr_t s2 = Serializer::serialize(&obj2);
		uintptr_t s3 = Serializer::serialize(&obj3);

		std::cout << "   obj1 serialized: " << s1 << std::endl;
		std::cout << "   obj2 serialized: " << s2 << std::endl;
		std::cout << "   obj3 serialized: " << s3 << std::endl;

		std::cout << "\n→ Deserializing in reverse order..." << std::endl;
		Data *r3 = Serializer::deserialize(s3);
		Data *r2 = Serializer::deserialize(s2);
		Data *r1 = Serializer::deserialize(s1);

		std::cout << "\n→ Verification:" << std::endl;
		std::cout << "   obj1: " << (&obj1 == r1
			&& r1->id == 1 ? "OK" : "FAIL") << std::endl;
		std::cout << "   obj2: " << (&obj2 == r2
			&& r2->id == 2 ? "OK" : "FAIL") << std::endl;
		std::cout << "   obj3: " << (&obj3 == r3
			&& r3->id == 3 ? "OK" : "FAIL") << std::endl;
	}

	std::cout << "\n=== TEST 3: Empty/zero values ===" << std::endl;
	{
		Data empty;
		empty.id = 0;
		empty.name = "";
		empty.value = 0.0;

		std::cout << "\n→ Object with empty/zero values:" << std::endl;
		std::cout << "   id:    " << empty.id << std::endl;
		std::cout << "   name:  '" << empty.name << "'" << std::endl;
		std::cout << "   value: " << empty.value << std::endl;

		uintptr_t serialized = Serializer::serialize(&empty);
		Data *restored = Serializer::deserialize(serialized);

		std::cout << "\n→ After serialize/deserialize:" << std::endl;
		std::cout << "   id:    " << restored->id << std::endl;
		std::cout << "   name:  '" << restored->name << "'" << std::endl;
		std::cout << "   value: " << restored->value << std::endl;

		std::cout << "\n→ Pointers match? " << (&empty == restored ? "YES" : "NO") << std::endl;
	}

	std::cout << "\n=== TEST 4: Subject requirement ===" << std::endl;
	{
		Data data;
		data.id = 100;
		data.name = "Subject Test";
		data.value = 99.99;

		std::cout << "\n→ Original pointer: " << &data << std::endl;

		uintptr_t raw = Serializer::serialize(&data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << "→ Restored pointer: " << ptr << std::endl;
		std::cout << "→ Pointers equal? " << (&data == ptr ? "YES" : "NO") << std::endl;
	}

	std::cout << "\n=== All tests completed! ===" << std::endl;

	return (0);
}