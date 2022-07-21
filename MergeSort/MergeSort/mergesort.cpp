#include <cstdlib>
#include "mergesort.h"

void mergeOutOfPlace(int list[], int size, int leftList[], int leftSize, int rightList[], int rightSize) {

	int leftIndex = 0;
	int rightIndex = 0;

	for(int index = 0; index < size; index++) {

		if(leftIndex == leftSize) {
			list[index] = rightList[rightIndex];
			rightIndex++;
		} else if(rightIndex == rightSize) {
			list[index] = leftList[leftIndex];
			leftIndex++;
		} else if(leftList[leftIndex] <= rightList[rightIndex]) {
			list[index] = leftList[leftIndex];
			leftIndex++;
		} else {
			list[index] = rightList[rightIndex];
			rightIndex++;
		}

	}
}

void sortOutOfPlace(int list[], int size) {
	sortOutOfPlaceHelper(list, size, 0, size - 1);
}

void sortOutOfPlaceHelper(int list[], int size, int left, int right) {

	// Base case: if there are 1 or less elements, then the array 
	// is already sorted
	if(left >= right) {
		return;
	}

	// We need the midpoint of the array
	int middle = (right - left) / 2;
	int leftSize = middle - left + 1;
	int rightSize = right - middle;

	// We need two auxillary arrays to hold both halves
	int* leftList = (int *)malloc(leftSize * sizeof(int));
	int* rightList = (int *)malloc(rightSize * sizeof(int));

	// Arrange the arrays
	for(int index = 0; index < leftSize; index++) {
		leftList[index] = list[index];
	}

	for(int index = 0; index < rightSize; index++) {
		rightList[index] = list[middle + 1 + index];
	}

	// Divide the two smaller arrays
	sortOutOfPlaceHelper(leftList, leftSize, 0, leftSize - 1);
	sortOutOfPlaceHelper(rightList, rightSize, 0, rightSize - 1);

	// Merge the two arrays into the original array
	mergeOutOfPlace(list, size, leftList, leftSize, rightList, rightSize);
}

void mergeInPlace(int list[], int left, int middle, int right) {

	int leftIndex = left;
	int rightIndex = middle + 1;

	int buffer = 0;
	int tempIndex = 0;

	while(leftIndex < rightIndex && rightIndex <= right) { // TODO: Modify this condition

		// Element at leftIndex is less than the one at rightIndex, so it is
		// in the right place
		if(list[leftIndex] <= list[rightIndex]) {
			leftIndex++;
		} else {

			// Here, the right element is less than the left one, so swap them
			buffer = list[leftIndex];
			list[leftIndex] = list[rightIndex];
			list[rightIndex] = buffer;

			// Bubble the element at rightIndex down to the correctg location
			for(tempIndex = rightIndex; tempIndex > leftIndex; tempIndex--) {

				// As soon as the right element is at the right location, break
				if(list[tempIndex] >= list[tempIndex - 1]) break;

				buffer = list[tempIndex - 1];
				list[tempIndex - 1] = list[tempIndex];
				list[tempIndex] = buffer;

			}

			// Increment both indices
			leftIndex++;
			rightIndex++;

		}

	}

}

void sortInPlace(int list[], int size) {
	sortInPlaceHelper(list, 0, size - 1);
}

void sortInPlaceHelper(int list[], int left, int right) {

	// Base case: if left >= right, thenm there is 1 element or less in the array
	if(left >= right) {
		return;
	}
	
	// We need to know where to split the list
	int middle = left + ((right - left) / 2);

	// Split the list in two and recurse on both sides
	sortInPlaceHelper(list, left, middle);
	sortInPlaceHelper(list, middle + 1, right);

	// Merge the two sorted subarrays
	mergeInPlace(list, left, middle, right);

}