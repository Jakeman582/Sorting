#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "quicksort.hpp"

using namespace std;

int main(int argc, char** argv) {

	// Make sure exactly 2 arguments are supplied
	if(argc != 2) {
		cout << "Usage: sort file_name" << endl;
		exit(0);
	}

	// Attempt to open the file
	ifstream input_file(argv[1]);
	if(!input_file.is_open()) {
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

	// Create a file to store the results
	string output_file_name = "SORTED.txt";
	ofstream output_file(output_file_name);
	if(!output_file.is_open()) {
		cout << "Failed to create file SORTED.txt for storing results" << endl;
		exit(0);
	}

	// Store the results in the file
	for(int index = 0; index < size; index++) {
		output_file << data[index];
		if(index < size - 1) {
			output_file << endl;
		}
	}
	output_file.close();

	return 0;
}
