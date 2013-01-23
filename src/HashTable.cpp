#include <cmath>
#include <iostream>
#include <string>
#include "HashTable.h"

// Constructor
HashTable::HashTable() {}

// Private functions

// Utility function to get hash of string. Wraps around at 100.
int HashTable::str2hash(std::string str)
{
	return std::hash<std::string>()(str) % 100;
}
// Public functions

// Adds a specified string to the HashTable
void HashTable::insert(std::string key, std::string value)
{
	int hash	=	str2hash(key);

	if (find(key) == NULL) {
		// Construct new Entry
		Entry *entry	=	new Entry;
		entry->key		=	key;
		entry->value	=	value;
		entry->hash		=	hash;
		entry->next		=	entries[hash];

		entries[hash]	=	entry; // Add new Entry to front
		std::cout << "item successfully inserted" << std::endl;
	} else { // Item already exists
		std::cout << "item already present" << std::endl;
	}
}
// Removes a specified string from the HashTable
void HashTable::remove(std::string key)
{
	bool	found	=	false;
	int		hash	=	str2hash(key);
	Entry*	curr = entries[hash];

	// Remove Entry containing key from array
	if (curr->key == key) { // Key is first
		entries[hash] = curr->next;
		found = true;
	} else {
		while (curr != NULL) { // Search for key
			if (curr->next->key == key) {
				curr->next = curr->next->next; // previousKey->next => nextKey
				found = true;
				break;
			}
			curr = curr->next;
		}
	}
	std::cout << "item " << (found ? "successfully deleted" :
		"not present in the table") << std::endl;
}
// Returns a reference to the instance of specified key in the HashTable if it
// exists.
std::string* HashTable::find(std::string key)
{
	Entry*	curr	=	NULL;
	int		hash	=	str2hash(key);

	curr = entries[hash];

	// Search for key
	while (curr != NULL) {
		if (curr->key == key) {
			std::cout << "item found" << std::endl;
			return &curr->value;
		}
		curr = curr->next;
	}
	return NULL;
}

