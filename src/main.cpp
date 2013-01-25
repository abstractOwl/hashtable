#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
	HashTable hashTable;

	while (true) {
		std::string	command,
					inval;

		std::cin >> command;
		std::cin >> inval;

		if (std::cin.eof()) break; // Exit if EOF detected

		// Perform command
		if (command == "insert") {
			hashTable.insert(inval, inval);
		} else if (command == "delete") {
			hashTable.remove(inval);
		} else if (command == "find") {
			std::cout << (hashTable.find(inval) == NULL ?
				"item not found" : "item found") << std::endl;
		} else {
			std::cout << "invalid command" << std::endl;
		}
	}
}

