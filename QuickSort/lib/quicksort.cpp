#include <cstdlib>
#include <ctime>
#include "quicksort.hpp"

void swap(int list[], int left, int right) {
	int buffer = list[left];
	list[left] = list[right];
	list[right] = buffer;
}

void swap(int& left, int& right) {
	int buffer = left;
	left = right;
	right = buffer;
}

void partition(int list[], int& pivot, int left, int right) {

	pivot = left;
	int local_pivot = pivot;
	int low = left + 1;
	int high = right;

	while(low <= high) {
		if(list[low] <= list[local_pivot]) {
			low++;
		} else {
			if(list[local_pivot] <= list[high]) {
				high--;
			} else {
				swap(list, low, high);
				high--;
			}
		}
	}

	swap(list, local_pivot, high);
	pivot = high;

}

void sortFirst(int list[], int size) {
	sortFirstHelper(list, 0, size - 1);
}

void sortFirstHelper(int list[], int left, int right) {

	// Base case: high <= low means we have a single number, or
	// not a list at all
	if(right <= left) {
		return;
	}

	// Partition the array
	int pivot;
	partition(list, pivot, left, right);

	// Recurse on either side of the pivot (without including the pivot)
	sortFirstHelper(list, left, pivot - 1);
	sortFirstHelper(list, pivot + 1, right);

}

void sortLast(int list[], int size) {
	sortLastHelper(list, 0, size - 1);
}

void sortLastHelper(int list[], int left, int right) {

	// Base case: if right <= left, then we got a single element at most
	if(right <= left) {
		return;
	}

	// Swap the first and last elements
	int pivot;
	swap(list, left, right);
	partition(list, pivot, left, right);

	// Recurse on either side of the pivot
	sortLastHelper(list, left, pivot - 1);
	sortLastHelper(list, pivot + 1, right);

}

void sortRandom(int list[], int size) {
	sortRandomHelper(list, 0, size - 1);
}

void sortRandomHelper(int list[], int left, int right) {

	// Base case
	if(right <= left) {
		return;
	}

	// Select the pivot randomly, and move the element to the first position
	srand(time(nullptr));
	int pivot = left + (rand() % (right - left + 1));
	swap(list, left, pivot);
	pivot = left;

	// Partition the array
	partition(list, pivot, left, right);

	// Recurse on either side
	sortRandomHelper(list, left, pivot - 1);
	sortRandomHelper(list, pivot + 1, right);

}

void sortMedian(int list[], int size) {
	sortMedianHelper(list, 0, size - 1);
}

void sortMedianHelper(int list[], int left, int right) {

	//int buffer;

	// Base case: if there is one element or less, simply return
	if(left >= right) {
		return;
	}

	// Base case: if there are only two elements, swap them if necessary
	if(right - left + 1 == 2) {
		if(list[left] > list[right]) swap(list, left, right);
		return;
	}

	// Base case: if there are 3 elements, do a quick sort
	if(right - left + 1 == 3) {
		if(list[left] > list[left + 1]) swap(list, left, left + 1);
		if(list[left] > list[right]) swap(list, left, right);
		if(list[left + 1] > list[right]) swap(list, left + 1, right);
		return;
	}

	// Here, use a pivot that is the median of 3 randomly picked indices
	srand(time(nullptr));
	int index1 = left + (rand() % (right - left + 1));
	int index2 = left + (rand() % (right - left + 1));
	while(index2 == index1) {
		index2 = left + (rand() % (right - left + 1));
	}
	int index3 = left + (rand() % (right - left + 1));
	while((index3 == index1) || (index3 == index2)) {
		index3 = left + (rand() % (right - left + 1));
	}

	// Sort the indices so index2 is the median
	if(index1 > index2) swap(index1, index2);
	if(index1 > index3) swap(index1, index3);
	if(index2 > index3) swap(index2, index3);

	int pivot = index2;

	// move the pivot to the start of the array
	swap(list, left, pivot);

	// Partition the array
	partition(list, pivot, left, right);

	// Recurse on either side of the pivot
	sortMedianHelper(list, left, pivot - 1);
	sortMedianHelper(list, pivot + 1, right);
}