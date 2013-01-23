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

	// Construct new Entry
	Entry *newEntry	=	new Entry;
	newEntry->key	=	key;
	newEntry->value	=	value;
	newEntry->hash	=	hash;
	newEntry->next	=	entries[hash];

	entries[hash]	=	newEntry; // Add new Entry to front
}
// Removes a specified string from the HashTable
void HashTable::remove(std::string key)
{
	int		hash	=	str2hash(key);
	Entry*	curr = entries[hash];

	// Remove Entry containing key from array
	if (curr->key == key) { // Key is first
		entries[hash] = curr->next;
	} else {
		while (curr != NULL) { // Search for key
			if (curr->next->key == key) {
				curr->next = curr->next->next; // previousKey->next => nextKey
				break;
			}
			curr = curr->next;
		}
	}
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
			return &curr->value;
		}
		curr = curr->next;
	}
	return NULL;
}

