// Generics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "SortIt.h"

int main()
{

    auto random_integer = []() {
        std::random_device rd;     // Only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
        std::uniform_int_distribution<int> uni(0, 100); // Guaranteed unbiased
        return uni(rng);};

    
    
      std::vector<int> v(10);
  //  std::generate(v.begin(), v.end(), random_integer);
  //  auto mySortProblem1 = SortIt_Using_Heap(v);
  //  auto SortedList = (Sorted *) SortIt::solveRecursive(mySortProblem1);
 //   std::cout << "List Sorted (recursive)"<< SortedList;

    std::generate(v.begin(), v.end(), random_integer);
    auto mySortProblem2 = SortIt_Using_Heap(v);
    auto SortedList = (Sorted*)SortIt::solveGreedy(mySortProblem2);
    std::cout << "List Sorted (Greedy)" << SortedList;

    std::generate(v.begin(), v.end(), random_integer);
    auto mySortProblem3 = SortIt_Using_Heap(v);
    auto SortedList2 = (Sorted*)SortIt::solveDivideAndConquer(mySortProblem3);
    std::cout << "List Sorted (Divide and Conquer)" << SortedList2;
}

