#include <cstdlib>
#include "countsort.h"

void sort(int list[], int size) {

	// If there is atmost 1 element, the array is sorted
	if(size <= 1) return;
	
	// We need to find the range, so we know how much space to allocate for our
	// count array
	int minimum = list[0];
	int maximum = list[0];
	for(int index = 0; index < size; index++) {
		if(maximum < list[index]) maximum = list[index];
		if(list[index] < minimum) minimum = list[index];
	}

	// If the minimum and maximum are the same, the list has only one
	// unique element, so it's sorted
	if(minimum == maximum) return;

	// Allocate an array so we can count each element, initialzed to all 0
	int range = maximum - minimum + 1;
	int *counts = (int *)calloc(range, sizeof(int));

	// The elements in the given list may not line up with the indices
	// in the count array, so we need to know the offset
	int offset = -1 * minimum;

	// Count the number of times each element appears in the array
	for(int index = 0; index < size; index++) {
		counts[list[index] + offset]++;
	}

	// Calculate the cumulative sum in the counts array
	for(int index = 1; index < range; index++) {
		counts[index] += counts[index - 1];
	}

	// Cache the contents of the original array
	int *cache = (int *)malloc(size * sizeof(int));
	for(int index = 0; index < size; index++) {
		cache[index] = list[index];
	}

	// Write the sorted elements in the original array
	for(int index = 0; index < size; index++) {
		int number = cache[index];
		counts[number + offset]--;
		list[counts[number + offset]] = number;
	}
}