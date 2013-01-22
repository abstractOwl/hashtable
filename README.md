# CS130A Programming Assignment 1: HashTable Implementation

## Objective:
---------------
* Implement the following functions with the specified constraints:
	* void insert(string key, string value)
		1. Insert the value in the correct bucket based on the hash of the key
		2. If the insertion is successful, print "item successfully inserted" to the standard output. Otherwise, print "item already present"
	* void delete(string key)
		1. Delete the corresponding item based on the key
		2. Print either "item successfully deleted" or "item not present in the table" to the standard output
	* string* find(string key)
		1. Look up the corresponding item based on the key
		2. Return "item found" or return NULL if the corresponding item does not exist

* Specific implementation points:
	* You can use std::string to represent the random string that will be stored in the hash table
	* For collision resolution, you should use separate chaining
	* You don't need to implement resize of hash table. We will tell you the size of the total items that needs to be stored in a hash table. When you make an instance of your hash table class in your main function, you can assume the max total number of items is 100. We will not test your programs with more than 100 items.
	* You can use std::hash<std::string> to calculate the hash value of a string
