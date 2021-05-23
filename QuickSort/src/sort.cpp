#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../lib/quicksort.hpp"

using namespace std;

int main(int argc, char** argv) {

	// Make sure exactly 2 arguments are supplied
	if(argc != 2) {
		cout << "Usage: sort file_name" << endl;
		exit(0);
	}

	// Attempt to open the file
	ifstream input_file(argv[1]);
	if(input_file.fail()) {
		cout << "Unable to open file \"" << argv[1] << "\"" << endl;
		exit(0);
	}

	// Read each integer from a file
	string number;
	vector<int> numbers;
	while(!input_file.eof()) {
		input_file >> number;
		numbers.push_back(stoi(number));
	}
	input_file.close();

	// Extract the data from the vector
	int *data = numbers.data();
	int size = (int) numbers.size();

	// Sort using the first element as pivot
	sortFirst(data, size);

	// Write results to stdout
	for(int index = 0; index < size; index++) {
		cout << data[index] << endl;
	}

	return 0;
}
