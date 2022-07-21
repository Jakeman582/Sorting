// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CATCH_CONFIG_MAIN 

#include <iostream>
#include <Catch2.hpp>
#include "mergesort.h"

using namespace std;

bool arraysAreEqual(int array1[], int size1, int array2[], int size2) {

	if(size1 != size2) return false;

	for(int index = 0; index < size1; index++) {
		if(array1[index] != array2[index]) return false;
	}

	return true;

}

TEST_CASE("Mergesort: Out-of-Place") {

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
	sortOutOfPlace(testArray0, 1);
	sortOutOfPlace(testArray1, 3);
	sortOutOfPlace(testArray2, 3);
	sortOutOfPlace(testArray3, 3);
	sortOutOfPlace(testArray4, 3);
	sortOutOfPlace(testArray5, 3);
	sortOutOfPlace(testArray6, 3);
	sortOutOfPlace(testArray7, 9);
	sortOutOfPlace(testArray8, 9);
	sortOutOfPlace(testArray9, 9);
	sortOutOfPlace(testArray10, 9);
	sortOutOfPlace(testArray11, 9);
	sortOutOfPlace(testArray12, 9);

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

TEST_CASE("Mergesort: In-Place") {

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
	sortInPlace(testArray0, 1);
	sortInPlace(testArray1, 3);
	sortInPlace(testArray2, 3);
	sortInPlace(testArray3, 3);
	sortInPlace(testArray4, 3);
	sortInPlace(testArray5, 3);
	sortInPlace(testArray6, 3);
	sortInPlace(testArray7, 9);
	sortInPlace(testArray8, 9);
	sortInPlace(testArray9, 9);
	sortInPlace(testArray10, 9);
	sortInPlace(testArray11, 9);
	sortInPlace(testArray12, 9);

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