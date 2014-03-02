#pragma once
//stl
#include <vector>
//own
#include "SortingPracticeInlined.h"

//known implementation wrappers
void stl_sort(std::vector<int> &input);

//own
void insertionSort(std::vector<int> &input);
void selectionSort(std::vector<int> &input);
void mergeSortRecursive(std::vector<int> &input);
void mergeSortIterative(std::vector<int> &input);
void quickSort(std::vector<int> &input);