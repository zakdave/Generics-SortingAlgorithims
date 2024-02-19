#pragma once
#include "Problem.h"
#include "Sorted.h"
#include <algorithm>
#include <iostream>
#include "SearchAndSortProblem.h"

class SortIt :
	public Problem
{
	std::vector<int> unsorted_values;
	std::vector<int> sorted_values;
	std::vector<int> heap;
	
public:

	SortIt();
	SortIt(std::vector<int> unsorted_values);
	SortIt(std::vector<int> unsorted_values, std::vector<int> sorted_values);
	SortIt(std::vector<int> unsorted_values, std::vector<int> sorted_values, std::vector<int> heap);
	
	bool trivial();
	bool solved();
	bool better(class Problem* Reference);
	std::vector<Problem*> make_subproblems();
	class aSolution* createSolution();
	class aSolution* combineSolutions(std::vector<aSolution*> partialSolutions); // in paper this is combine
	class Problem* simplifyProblem();  // in paper this is called refine
	class Problem* applyBestAction();
	class Problem* applyRandomAction();
	std::vector<int> merge(std::vector<int> L1, std::vector<int> L2);
};

// Class factory like function to create the problem.
class Problem* SortIt_Using_Heap(std::vector<int> values_to_sort);

