#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
	HashTable myTable;

	while (true) {
		int	delimPos;
		std::string	command,
					inval;

		std::cin >> command;
		std::cin >> inval;

		if (command == "insert") {
		} else if (command == "delete") {
		} else if (command == "find") {
			
		} else {
			std::cout << "invalid command" << std::endl;
		}
	}
}

