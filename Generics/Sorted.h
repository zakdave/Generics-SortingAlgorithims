#pragma once
#include "aSolution.h"
#include <iostream>
class Sorted :
    public aSolution
{
public:
	std::vector<int> sorted_list;

	Sorted() { return; };
	Sorted(std::vector<int> unsorted_values, std::vector<int> sorted_values) {  
		
		sorted_list.insert(sorted_list.end(), sorted_values.begin(), sorted_values.end());
		sorted_list.insert(sorted_list.end(), unsorted_values.begin(), unsorted_values.end());

		return; 
	};
};

inline std::ostream& operator<<(std::ostream& os, const Sorted* res)
{
	os << "[";
	for (auto el : res->sorted_list)
		os << el<<",";
	os << "]"<<std::endl;
	return os;
}
