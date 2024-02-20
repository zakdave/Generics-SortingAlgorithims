#include <vector>
#include <algorithm>
#include "SearchAndSortProblem.h"
#include "SearchAndSortSolution.h"




class aSolution* SearchAndSortProblem::heapSort(class SearchAndSortProblem* aProblem) {
	std::make_heap(aProblem->values.begin(), aProblem->values.end());
	std::sort_heap(aProblem->values.begin(), aProblem->values.end());
	return new SearchAndSortSolution(aProblem->values);
}

class aSolution* SearchAndSortProblem::mergeSort(class SearchAndSortProblem* aProblem) {
	int value_length = aProblem->values.size() - 1;
    merge(aProblem->values, aProblem->left, aProblem->middle, aProblem->right);
	mergeSortHelper(aProblem->values, 0, value_length);
    return new SearchAndSortSolution(aProblem->values);
}

class aSolution* SearchAndSortProblem::quickSort(class SearchAndSortProblem* aProblem) {
	int value_length = aProblem->values.size() - 1;
	partition(aProblem->values, aProblem->low, aProblem->high);
	quickSortHelper(aProblem->values, 0, value_length);
	return new SearchAndSortSolution(aProblem->values);
}

//Class Factories
 class SearchAndSortProblem* createSSProblem(std::vector<int> values_to_sort)
{
	return new SearchAndSortProblem(values_to_sort);

}

 class SearchAndSortProblem* createSSProblem(std::vector<int> values_to_sort, int left_index, int middle_index, int right_index)
 {
	 return new SearchAndSortProblem(values_to_sort, left_index, middle_index, right_index);

 }

 