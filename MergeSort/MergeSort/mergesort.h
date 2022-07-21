#pragma once

void mergeOutOfPlace(int list[], int size, int leftList[], int leftSize, int rightList[], int rightSize);
void mergeInPlace(int list[], int left, int middle, int right);

void sortOutOfPlace(int list[], int size);
void sortOutOfPlaceHelper(int list[], int size, int left, int right);

void sortInPlace(int list[], int size);
void sortInPlaceHelper(int list[], int left, int right);