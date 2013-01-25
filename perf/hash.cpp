#include <fstream>
#include <iostream>
#include <string>
#include <sys/time.h>
#include "HashTable.h"


int main(int argc, char *argv[])
{
	HashTable hashTable;
	int idx = 0;
	std::string word, srch_strs[100];

	// Load test strings
	std::ifstream testFile(std::string("test_files/testfile_")
		.append(argv[1]));

	while (testFile >> word) {
		hashTable.insert(word, word);
		idx++;
	}
	testFile.close();

	// Load srch strings
	int idx2 = 0;
	std::ifstream srchFile(std::string("test_files/100str_").append(argv[1]));
	while (srchFile >> word) {
		srch_strs[idx2++] = word;
	}
	srchFile.close();

	// Perform hashtable search
	timeval t1, t2;
	double elapsedTime;

	gettimeofday(&t1, NULL);

	// Perform operations
	for (int i = 0; i < 100; i++) {
		hashTable.find(srch_strs[i]);
	}

	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	std::cout << (int)(elapsedTime * 1000);
}

