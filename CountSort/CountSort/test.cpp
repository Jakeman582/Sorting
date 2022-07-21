#include <catch_amalgamated.hpp>
#include "countsort.h"

#define CATCH_CONFIG_MAIN

bool arraysAreEqual(int list1[], int size1, int list2[], int size2) {

	if(size1 != size2) return false;

	for(int index = 0; index < size1; index++) {
		if(list1[index] != list2[index]) return false;
	}

	return true;

}

SCENARIO("Countsort") {

	// Sorted arrays
	int sortedArray0[] = { 1};
	int sortedArray1[] = { 1,  2,  3};
	int sortedArray2[] = {-3, -2, -1};
	int sortedArray3[] = {-1,  0,  1};
	int sortedArray4[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9};
	int sortedArray5[] = {-9, -8, -7, -6, -5, -4, -3, -2, -1};
	int sortedArray6[] = {-4, -3, -2, -1,  0,  1,  2,  3,  4};
	int sortedArray7[] = { 1,  2,  2,  3,  3,  3,  4,  4,  4,  4};
	int sortedArray8[] = {-3, -2, -2, -1,  0,  0,  2,  2,  2,  3,  3};

	// Unsorted arrays for testing
	int testArray0[]  = { 1};
	int testArray1[]  = { 1,  2,  3};
	int testArray2[]  = { 2,  3,  1};
	int testArray3[]  = { 3,  2,  1};
	int testArray4[]  = {-3, -2, -1};
	int testArray5[]  = {-2, -1, -3};
	int testArray6[]  = {-1, -2, -3};
	int testArray7[]  = {-1,  0,  1};
	int testArray8[]  = { 0,  1, -1};
	int testArray9[]  = { 1,  0, -1};
	int testArray10[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9};
	int testArray11[] = { 9,  2,  7,  4,  5,  6,  3,  8,  1};
	int testArray12[] = { 9,  8,  7,  6,  5,  4,  3,  2,  1};
	int testArray13[] = {-9, -8, -7, -6, -5, -4, -3, -2, -1};
	int testArray14[] = {-2, -4, -6, -8, -1, -3, -5, -7, -9};
	int testArray15[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
	int testArray16[] = {-4, -3, -2, -1,  0,  1,  2,  3,  4};
	int testArray17[] = { 0,  1, -1,  2, -2,  3, -3,  4, -4};
	int testArray18[] = { 4,  3,  2,  1,  0, -1, -2, -3, -4};
	int testArray19[] = { 3,  4,  4,  1,  2,  3,  4,  2,  4,  3};
	int testArray20[] = { 0, -1,  2, -2,  2, -2,  2,  3, -3,  3,  0};

	// Sort the arrays
	sort(testArray0, 1);
	sort(testArray1, 3);
	sort(testArray2, 3);
	sort(testArray3, 3);
	sort(testArray4, 3);
	sort(testArray5, 3);
	sort(testArray6, 3);
	sort(testArray7, 3);
	sort(testArray8, 3);
	sort(testArray9, 3);
	sort(testArray10, 9);
	sort(testArray11, 9);
	sort(testArray12, 9);
	sort(testArray13, 9);
	sort(testArray14, 9);
	sort(testArray15, 9);
	sort(testArray16, 9);
	sort(testArray17, 9);
	sort(testArray18, 9);
	sort(testArray19, 10);
	sort(testArray20, 11);

	GIVEN("Arrays with 1 element") {
		REQUIRE(arraysAreEqual(sortedArray0, 1, testArray0, 1));
	}

	GIVEN("Arrays with 3 elements") {
		REQUIRE(arraysAreEqual(sortedArray1, 3, testArray1, 3));
		REQUIRE(arraysAreEqual(sortedArray1, 3, testArray2, 3));
		REQUIRE(arraysAreEqual(sortedArray1, 3, testArray3, 3));
		REQUIRE(arraysAreEqual(sortedArray2, 3, testArray4, 3));
		REQUIRE(arraysAreEqual(sortedArray2, 3, testArray5, 3));
		REQUIRE(arraysAreEqual(sortedArray2, 3, testArray6, 3));
		REQUIRE(arraysAreEqual(sortedArray3, 3, testArray7, 3));
		REQUIRE(arraysAreEqual(sortedArray3, 3, testArray8, 3));
		REQUIRE(arraysAreEqual(sortedArray3, 3, testArray9, 3));
	}

	GIVEN("Arrays with 9 elements") {
		REQUIRE(arraysAreEqual(sortedArray4, 1, testArray10, 1));
		REQUIRE(arraysAreEqual(sortedArray4, 1, testArray11, 1));
		REQUIRE(arraysAreEqual(sortedArray4, 1, testArray12, 1));
		REQUIRE(arraysAreEqual(sortedArray5, 1, testArray13, 1));
		REQUIRE(arraysAreEqual(sortedArray5, 1, testArray14, 1));
		REQUIRE(arraysAreEqual(sortedArray5, 1, testArray15, 1));
		REQUIRE(arraysAreEqual(sortedArray6, 1, testArray16, 1));
		REQUIRE(arraysAreEqual(sortedArray6, 1, testArray17, 1));
		REQUIRE(arraysAreEqual(sortedArray6, 1, testArray18, 1));
	}

	GIVEN("Arrays with duplicates") {
		REQUIRE(arraysAreEqual(sortedArray7, 10, testArray19, 10));
		REQUIRE(arraysAreEqual(sortedArray8, 11, testArray20, 11));
	}

}

//#include "countsort.h"
//int main() {
//	int list[] = { 1, 2, 3 };
//	sort(list, 3);
//	return 0;
//}