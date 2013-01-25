#include <fstream>
#include <iostream>
#include <string>
#include <sys/time.h>

std::string* linearSearch(std::string *strsPtr, std::string key, int size)
{
	for (int i = 0; i < size; i++) {
		if (strsPtr[i] == key) {
			return strsPtr;
		}
	}
}

int main(int argc, char *argv[])
{
	int idx = 0, size = 5000000;
	std::string word, srch_strs[100];

	if (argv[1] == "1m") {
		size = 1000000;
	} else if (argv[1] == "3m") {
		size = 3000000;
	}
	std::string* test_strs = new std::string[size];

	// Load test strings
	std::ifstream testFile(std::string("test_files/testfile_").append(argv[1]));


	while (testFile >> word) {
		test_strs[idx++] = word;
	}
	testFile.close();

	// Load srch strings
	int idx2 = 0;
	std::ifstream srchFile(std::string("test_files/100str_").append(argv[1]));
	while (srchFile >> word) {
		srch_strs[idx2++] = word;
	}
	srchFile.close();

	// Perform linear search
	timeval t1, t2;
	double elapsedTime;

	gettimeofday(&t1, NULL);

	// Perform operations
	for (int i = 0; i < 100; i++) {
		linearSearch(test_strs, srch_strs[i], size) == NULL;
	}

	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	std::cout << (int)(elapsedTime * 1000);
}

