#pragma once
#include "SearchAndSortProblem.h"
#include <vector>
#include "aSolution.h"

class SearchAndSortProblem 
{
	std::vector<int>values;
	int left = 0;
	int middle = 0;
	int right = 0;
    int low = 0;
    int high = 0;

public:
	SearchAndSortProblem(std::vector<int>& values_to_sort) {
		values = values_to_sort;

		return;
	};
    SearchAndSortProblem(std::vector<int>& values_to_sort, int low_value, int high_value) {
        values = values_to_sort;
        low = low_value;
        high = high_value;

        return;
    }

	SearchAndSortProblem(std::vector<int>& values_to_sort, int left_index, int middle_index, int right_index) {
		values = values_to_sort;
		left = left_index;
		middle = middle_index;
		right = right_index;

		return;
	};

    static void merge(std::vector<int>& vec, int left, int middle, int right) {
        int leftSize = middle - left + 1;
        int rightSize = right - middle;

        std::vector<int> leftArray(leftSize);
        std::vector<int> rightArray(rightSize);

        // Copy data to temporary arrays leftArray[] and rightArray[]
        for (int i = 0; i < leftSize; ++i)
            leftArray[i] = vec[left + i];
        for (int j = 0; j < rightSize; ++j)
            rightArray[j] = vec[middle + 1 + j];

        // Merge the temporary arrays back into arr[left, right]
        int i = 0, j = 0, k = left;
        while (i < leftSize && j < rightSize) {
            if (leftArray[i] <= rightArray[j]) {
                vec[k] = leftArray[i];
                ++i;
            }
            else {
                vec[k] = rightArray[j];
                ++j;
            }
            ++k;
        }

        // Copy the remaining elements of leftArray[], if any
        while (i < leftSize) {
            vec[k] = leftArray[i];
            ++i;
            ++k;
        }

        // Copy the remaining elements of rightArray[], if any
        while (j < rightSize) {
            vec[k] = rightArray[j];
            ++j;
            ++k;
        }
    }
    static void mergeSortHelper(std::vector<int>& vec, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            // Sort first and second halves
            mergeSortHelper(vec, left, middle);
            mergeSortHelper(vec, middle + 1, right);

            // Merge the sorted halves
            merge(vec, left, middle, right);
        }
    }
    static int partition(std::vector<int>& vec, int low, int high) {
        int pivot = vec[high];  // last as pivot
        int i = low - 1;  // index of the smaller 

        for (int j = low; j < high; ++j) {
            // if the current element is smaller than or equal to the pivot
            if (vec[j] <= pivot) {
                // swap arr[i] and arr[j]
                std::swap(vec[++i], vec[j]);
            }
        }

        // swap pivot
        std::swap(vec[i + 1], vec[high]);

        return i + 1;
    }
    static void quickSortHelper(std::vector<int>& vec, int low, int high) {
        if (low < high) {
            // partition index
            int part = partition(vec, low, high);

            // recursive calls
            quickSortHelper(vec, low, part - 1);
            quickSortHelper(vec, part + 1, high);
        }
    }

	static class aSolution* heapSort(class SearchAndSortProblem*);
	static class aSolution* mergeSort(class SearchAndSortProblem*);
	static class aSolution* quickSort(class SearchAndSortProblem*);
};

// Create class factory
class SearchAndSortProblem* createSSProblem(std::vector<int> values_to_sort);