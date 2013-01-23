#include <cmath>
#include <string>
#include "HashTable.h"

// Constructors
HashTable::HashTable()
{
	// Default to 100 index array
	HashTable(100);
}
HashTable::HashTable(int maxSize)
{
	entries	=	new Entry[size];
	size	=	maxSize;
}

// Private functions

/**
 * Utility function to get hash of string
 */
int HashTable::str2hash(std::string str)
{
	return std::hash<std::string>()(str);
}
/**
 * Given a key, find its location in the array using binary search
 */
int HashTable::indexOf(std::string key)
{
	return indexOfHelper(str2hash(key), 0, size);
}
/**
 * Performs recursion for indexOf()
 */
int HashTable::indexOfHelper(int hash, int start, int end)
{
	int midpoint = (int)floor((start + end) / 2);

	if (start > end) return -1; // hash not found!

	if (entries[midpoint].hash == hash) { // hash found
		return midpoint;
	} else if (entries[midpoint].hash > hash) {
		// midpoint + 1 because we tested midpoint already
		return indexOfHelper(hash, midpoint + 1, end);
	} else { // if entries[midpoint].hash < hash
		// midpoint - 1 because we tested midpoint already
		return indexOfHelper(hash, start, midpoint - 1);
	}
}

// Public functions
/**
 * Adds a specified string to the HashTable
 */
void HashTable::insert(std::string key, std::string value)
{
	// @@TODO: Fill in function body
	// REMEMBER TO SET entry->next TO NULL
}
/**
 * Removes a specified string from the HashTable
 */
void HashTable::remove(std::string key)
{
	Entry*	curr;
	int	pos;

	// @@TODO: Fill in function body
	pos = indexOf(key); // Locate key in array
	
	if (pos == -1) { // key not found!
		cout << "item not found!"
	}

	curr = &entries[pos];

	// Remove Entry containing key from array
	if (curr->value == key) {
		entries[pos] = &curr->next;
	} else {
		while (curr != null) {
			if (curr->next->string == key) {
				curr->next = curr->next->next;
				break;
			}
			curr = curr->next;
		}
	}

	// @@TODO: Clean up if arr index is empty
}
/**
 * Returns a reference to the instance of specified key in the HashTable if it
 * exists.
 */
std::string* HashTable::find(std::string key)
{
	Entry*	curr	=	NULL;
	int	hash	=	str2hash(key),
		pos;

	pos = indexOf(key); // Locate key in array
	
	if (pos == -1) return NULL; // key not found!

	curr = &entries[pos];

	// Search for key
	while (curr != null) {
		if (curr->string == key) {
			return curr;
		}
		curr = curr->next;
	}
	return NULL; // key not found! this shouldn't happen though.
}
