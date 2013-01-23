#include <string>

/**
 * Entry is one element in the HashTable. Entry contains properties "value",
 * which contains the value of the entry, and "next", which holds a reference
 * to another value with the same hash if there is one.
 */
struct Entry
{
	std::string	value;
	int			hash;
	Entry*		next;
};

/**
 * HashTable is a data structure containing <key, value> pairs.
 */
class HashTable
{
public:
	HashTable();
	HashTable(int maxSize);
	void			insert(std::string key, std::string value);
	void			remove(std::string key);
	std::string*	find(std::string key);
private:
	Entry	*entries; // Array holding Entry items
	int		size;

	int	indexOf(std::string key);
	int	indexOfHelper(int hash, int start, int end);
	int	str2hash(std::string str);
};
