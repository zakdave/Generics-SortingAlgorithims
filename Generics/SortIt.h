#pragma once
#include "Problem.h"
#include "Sorted.h"
#include <algorithm>
#include <iostream>

class SortIt :
    public Problem
{
	std::vector<int> unsorted_values;
	std::vector<int> sorted_values;
	std::vector<int> heap;
	
public:

	SortIt();
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
};

// Class factory like function to create the problem.
class Problem* SortIt_Using_Heap(std::vector<int> values_to_sort);

