#pragma once
#pragma once
#include "aSolution.h"
#include <iostream>
#include <vector>

class SearchAndSortSolution:
	public aSolution
{
public:
	std::vector<int> sorted_list;


	SearchAndSortSolution() { return; };
	SearchAndSortSolution(std::vector<int> sorted_values) {
		sorted_list.insert(sorted_list.end(), sorted_values.begin(), sorted_values.end());
		return;
	};
};

inline std::ostream& operator<<(std::ostream& os, const SearchAndSortSolution* res)
{
	os << "[";
	for (auto el : res->sorted_list)
		os << el << ",";
	os << "]" << std::endl;
	return os;
}
