#include "SortIt.h"
#include "Sorted.h"
#include <vector>
#include <random>

SortIt::SortIt() {

	return;
}


SortIt::SortIt(std::vector<int> values_to_sort, std::vector<int> values_sorted, std::vector<int> Heap) {
	 unsorted_values=values_to_sort;
	 sorted_values =  values_sorted;
	 
	 heap = Heap;
	 
	return;
}

// This is a class Factory, it hides the "new" and reduces the number of parameters seen by the user.
 class Problem * SortIt_Using_Heap(std::vector<int> values_to_sort)
{
	std::vector<int> Heap;
	Heap = std::vector<int>(values_to_sort);
	std::make_heap(Heap.begin(),Heap.end(), std::greater<>{});
	return new SortIt(values_to_sort, std::vector<int>{}, Heap);
	
}

bool SortIt::trivial() { return unsorted_values.size() < 1; };

bool SortIt::better(class Problem* Reference) { return true; };

bool SortIt::solved() {
	// this checks to see if the elements in the list are in ascending order.
	// if so, this sets sorted to the list and returns true, otherwise it returns false.
	// Riley Knybel 3/22/2023
	return std::is_sorted(unsorted_values.begin(), unsorted_values.end());
	// Riley Knybel 3/22/2023
}

class Problem* SortIt::applyRandomAction() {
	

	
	return new SortIt();
}

// we will split the unsorted lists into two problems with unsorted lists
std::vector<Problem*> SortIt::make_subproblems() {
	
	// Make two new problems, of each half of the current unsorted parts.
	// if the size of the split vector is 1, create a problem with an empty list to sort with the solution set to the 
	// element.  This is since we consider a trival problem to sort is the empty list.
	auto v = this->unsorted_values;
	if (v.size() == 1)
		return std::vector<Problem*>{new SortIt(std::vector<int>{}, v, v)};
	
	std::size_t const half_size = v.size() / 2;
	std::vector<int> split_lo(v.begin(), v.begin() + half_size);
	std::vector<int> split_hi(v.begin() + half_size, v.end());
	
	return std::vector<Problem*>{SortIt_Using_Heap(split_lo), SortIt_Using_Heap(split_hi)};
};
// Create solution will be called with a unsorted list of a single element and a sorted list.
class aSolution* SortIt::createSolution() 
{   // trival problems are empty lists with a single element in the sorted part.
	return new Sorted(unsorted_values,sorted_values); 
};

// This is a helper function.
std::vector<int> merge(std::vector<int> L1, std::vector<int> L2)
{
	std::vector<int> output(L1.size() + L2.size());
	auto it1 = L1.begin();
	auto it2 = L2.begin();
	auto ito = output.begin();

	while (it1 != L1.end())
	{
		auto el1 = *it1++;

		if (it2 != L2.end())
		{
			while (el1 > *it2)
			{
				*ito++ = *it2++;
				if (it2 == L2.end()) break;
			}
		}
		*ito++ = el1;
	}

	while (it2 != L2.end())
	{
		*ito++ = *it2++;  //bug 1/27 in class...
	}
	return output;
}

class aSolution* SortIt::combineSolutions(std::vector<aSolution*> partialSolutions) { 
	// given two problems with sorted arrays, create a new solution which is the merged in order list.
	if (partialSolutions.size() == 1) return (Sorted*)partialSolutions[0];

	auto S1 = ((Sorted *)partialSolutions[0])->sorted_list;
	auto S2 = ((Sorted *)partialSolutions[1])->sorted_list;

	auto S3 = merge(S1, S2);
	return new Sorted(std::vector<int>{},S3);
}; // in paper this is combine
// to simplify the problem, we get the max in the unsorted portion of the list and prepend in to the sorted list
// if the max is not defined we need to find it

class Problem* SortIt::simplifyProblem() { 
	// find the min value
	auto min = heap.front();
	// remove it from the unsorted list (or Heap)
	std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
	heap.pop_back();
	// append it to the sorted list
	
	sorted_values.push_back(min);
	// return the new problem
	return new SortIt(heap,sorted_values,heap); // the heap are the values
};  // in paper this is called refine

// selectBestAction in this case uses a Heap to select the max.   But in this case it is wrapped into simplify problem.
class Problem* SortIt::applyBestAction() {
	return new SortIt();
};
