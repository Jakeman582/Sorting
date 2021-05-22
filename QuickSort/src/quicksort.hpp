#pragma once

void swap(int list[], int left, int right);
void swap(int& left, int& right);

void partition(int list[], int& pivot, int left, int right);

void sortFirst(int list[], int size);
void sortFirstHelper(int list[], int left, int right);

void sortLast(int list[], int size);
void sortLastHelper(int list[], int left, int right);

void sortRandom(int list[], int size);
void sortRandomHelper(int list[], int left, int right);

void sortMedian(int list[], int size);
void sortMedianHelper(int list[], int left, int right);