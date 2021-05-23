// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#define CATCH_CONFIG_MAIN

#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../ext/Catch2/catch_amalgamated.hpp"
#include "../lib/quicksort.hpp"

using namespace std;

bool arraysAreEqual(int array1[], int size1, int array2[], int size2) {

	if(size1 != size2) return false;

	for(int index = 0; index < size1; index++) {
		if(array1[index] != array2[index]) return false;
	}

	return true;

}

TEST_CASE("Quicksort: First Element as Pivot") {

	// Sorted array of size 9
	int sortedArray0[] = {1};
	int sortedArray1[] = {1, 2, 3};
	int sortedArray2[] = {-3, -2, -1};
	int sortedArray3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sortedArray4[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};

	// Test arrays
	int testArray0[] = {1};
	int testArray1[] = {1, 2, 3};
	int testArray2[] = {2, 3, 1};
	int testArray3[] = {3, 2, 1};
	int testArray4[] = {-3, -2, -1};
	int testArray5[] = {-2, -1, -3};
	int testArray6[] = {-1, -2, -3};
	int testArray7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int testArray8[] = {5, 9, 2, 8, 3, 7, 4, 6, 1};
	int testArray9[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int testArray10[] = {-4, -3, -2, -1,  0,  1,  2,  3,  4};
	int testArray11[] = { 0,  1, -1,  2, -2,  3, -3,  4, -4};
	int testArray12[] = { 4,  3,  2,  1,  0, -1, -2, -3, -4};

	// Sort the arrays
	sortFirst(testArray0, 1);
	sortFirst(testArray1, 3);
	sortFirst(testArray2, 3);
	sortFirst(testArray3, 3);
	sortFirst(testArray4, 3);
	sortFirst(testArray5, 3);
	sortFirst(testArray6, 3);
	sortFirst(testArray7, 9);
	sortFirst(testArray8, 9);
	sortFirst(testArray9, 9);
	sortFirst(testArray10, 9);
	sortFirst(testArray11, 9);
	sortFirst(testArray12, 9);

	// Test Cases
	SECTION("Arrays with 1 element") {
		REQUIRE(arraysAreEqual(testArray0, 1, sortedArray0, 1));
	}

	SECTION("Arrays with 3 elements") {
		REQUIRE(arraysAreEqual(testArray1, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray2, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray3, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray4, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray5, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray6, 3, sortedArray2, 3));
	}

	SECTION("Arrays with 9 elements") {
		REQUIRE(arraysAreEqual(testArray7, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray8, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray9, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray10, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray11, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray12, 9, sortedArray4, 9));
	}

}

TEST_CASE("Quicksort: Last Element as Pivot") {

	// Sorted array of size 9
	int sortedArray0[] = { 1 };
	int sortedArray1[] = { 1, 2, 3 };
	int sortedArray2[] = { -3, -2, -1 };
	int sortedArray3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sortedArray4[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };

	// Test arrays
	int testArray0[] = { 1 };
	int testArray1[] = { 1, 2, 3 };
	int testArray2[] = { 2, 3, 1 };
	int testArray3[] = { 3, 2, 1 };
	int testArray4[] = { -3, -2, -1 };
	int testArray5[] = { -2, -1, -3 };
	int testArray6[] = { -1, -2, -3 };
	int testArray7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int testArray8[] = { 5, 9, 2, 8, 3, 7, 4, 6, 1 };
	int testArray9[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int testArray10[] = { -4, -3, -2, -1,  0,  1,  2,  3,  4 };
	int testArray11[] = { 0,  1, -1,  2, -2,  3, -3,  4, -4 };
	int testArray12[] = { 4,  3,  2,  1,  0, -1, -2, -3, -4 };

	// Sort the arrays
	sortLast(testArray0, 1);
	sortLast(testArray1, 3);
	sortLast(testArray2, 3);
	sortLast(testArray3, 3);
	sortLast(testArray4, 3);
	sortLast(testArray5, 3);
	sortLast(testArray6, 3);
	sortLast(testArray7, 9);
	sortLast(testArray8, 9);
	sortLast(testArray9, 9);
	sortLast(testArray10, 9);
	sortLast(testArray11, 9);
	sortLast(testArray12, 9);

	// Test Cases
	SECTION("Arrays with 1 element") {
		REQUIRE(arraysAreEqual(testArray0, 1, sortedArray0, 1));
	}

	SECTION("Arrays with 3 elements") {
		REQUIRE(arraysAreEqual(testArray1, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray2, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray3, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray4, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray5, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray6, 3, sortedArray2, 3));
	}

	SECTION("Arrays with 9 elements") {
		REQUIRE(arraysAreEqual(testArray7, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray8, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray9, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray10, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray11, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray12, 9, sortedArray4, 9));
	}

}

TEST_CASE("Quicksort: Random Element as Pivot") {

	// Sorted array of size 9
	int sortedArray0[] = { 1 };
	int sortedArray1[] = { 1, 2, 3 };
	int sortedArray2[] = { -3, -2, -1 };
	int sortedArray3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sortedArray4[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };

	// Test arrays
	int testArray0[] = { 1 };
	int testArray1[] = { 1, 2, 3 };
	int testArray2[] = { 2, 3, 1 };
	int testArray3[] = { 3, 2, 1 };
	int testArray4[] = { -3, -2, -1 };
	int testArray5[] = { -2, -1, -3 };
	int testArray6[] = { -1, -2, -3 };
	int testArray7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int testArray8[] = { 5, 9, 2, 8, 3, 7, 4, 6, 1 };
	int testArray9[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int testArray10[] = { -4, -3, -2, -1,  0,  1,  2,  3,  4 };
	int testArray11[] = { 0,  1, -1,  2, -2,  3, -3,  4, -4 };
	int testArray12[] = { 4,  3,  2,  1,  0, -1, -2, -3, -4 };

	// Sort the arrays
	sortRandom(testArray0, 1);
	sortRandom(testArray1, 3);
	sortRandom(testArray2, 3);
	sortRandom(testArray3, 3);
	sortRandom(testArray4, 3);
	sortRandom(testArray5, 3);
	sortRandom(testArray6, 3);
	sortRandom(testArray7, 9);
	sortRandom(testArray8, 9);
	sortRandom(testArray9, 9);
	sortRandom(testArray10, 9);
	sortRandom(testArray11, 9);
	sortRandom(testArray12, 9);

	// Test Cases
	SECTION("Arrays with 1 element") {
		REQUIRE(arraysAreEqual(testArray0, 1, sortedArray0, 1));
	}

	SECTION("Arrays with 3 elements") {
		REQUIRE(arraysAreEqual(testArray1, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray2, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray3, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray4, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray5, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray6, 3, sortedArray2, 3));
	}

	SECTION("Arrays with 9 elements") {
		REQUIRE(arraysAreEqual(testArray7, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray8, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray9, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray10, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray11, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray12, 9, sortedArray4, 9));
	}

}

TEST_CASE("Quicksort: Median Element as Pivot") {

	// Sorted array of size 9
	int sortedArray0[] = { 1 };
	int sortedArray1[] = { 1, 2, 3 };
	int sortedArray2[] = { -3, -2, -1 };
	int sortedArray3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sortedArray4[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };

	// Test arrays
	int testArray0[] = { 1 };
	int testArray1[] = { 1, 2, 3 };
	int testArray2[] = { 2, 3, 1 };
	int testArray3[] = { 3, 2, 1 };
	int testArray4[] = { -3, -2, -1 };
	int testArray5[] = { -2, -1, -3 };
	int testArray6[] = { -1, -2, -3 };
	int testArray7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int testArray8[] = { 5, 9, 2, 8, 3, 7, 4, 6, 1 };
	int testArray9[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int testArray10[] = { -4, -3, -2, -1,  0,  1,  2,  3,  4 };
	int testArray11[] = { 0,  1, -1,  2, -2,  3, -3,  4, -4 };
	int testArray12[] = { 4,  3,  2,  1,  0, -1, -2, -3, -4 };

	// Sort the arrays
	sortMedian(testArray0, 1);
	sortMedian(testArray1, 3);
	sortMedian(testArray2, 3);
	sortMedian(testArray3, 3);
	sortMedian(testArray4, 3);
	sortMedian(testArray5, 3);
	sortMedian(testArray6, 3);
	sortMedian(testArray7, 9);
	sortMedian(testArray8, 9);
	sortMedian(testArray9, 9);
	sortMedian(testArray10, 9);
	sortMedian(testArray11, 9);
	sortMedian(testArray12, 9);

	// Test Cases
	SECTION("Arrays with 1 element") {
		REQUIRE(arraysAreEqual(testArray0, 1, sortedArray0, 1));
	}

	SECTION("Arrays with 3 elements") {
		REQUIRE(arraysAreEqual(testArray1, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray2, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray3, 3, sortedArray1, 3));
		REQUIRE(arraysAreEqual(testArray4, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray5, 3, sortedArray2, 3));
		REQUIRE(arraysAreEqual(testArray6, 3, sortedArray2, 3));
	}

	SECTION("Arrays with 9 elements") {
		REQUIRE(arraysAreEqual(testArray7, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray8, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray9, 9, sortedArray3, 9));
		REQUIRE(arraysAreEqual(testArray10, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray11, 9, sortedArray4, 9));
		REQUIRE(arraysAreEqual(testArray12, 9, sortedArray4, 9));
	}

}