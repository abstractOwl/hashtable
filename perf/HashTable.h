#define SIZE 1000003
#include <string>

// Entry is one element in the HashTable
typedef struct Entry Entry;
struct Entry
{
	std::string	key;
	std::string	value;
	int			hash;
	Entry*		next; // Pointer to next item with same hash or NULL
};

// HashTable is a data structure containing <key, value> pairs.
class HashTable
{
public:
	HashTable();
	void			insert(std::string key, std::string value);
	void			remove(std::string key);
	std::string*	find(std::string key);
private:
	Entry*			entries[SIZE]; // Array holding pointers to Entry items
	int				size;
	int				str2hash(std::string str);
};

