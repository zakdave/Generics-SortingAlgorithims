// Generics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "SortIt.h"
#include "SearchAndSortProblem.h"
#include "SearchAndSortSolution.h"
#include <chrono>

int main()
{

    auto random_integer = []() {
        std::random_device rd;     // Only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
        std::uniform_int_distribution<int> uni(0, 100); // Guaranteed unbiased
        return uni(rng);};

    //timing
    std::chrono::microseconds microsec;
    std::chrono::microseconds microsec2;
    std::chrono::microseconds microsec3;
    std::chrono::microseconds microsec4;
    std::chrono::microseconds microsec5;
    std::chrono::microseconds microsec6;
    std::chrono::microseconds microsec7;
    std::chrono::steady_clock::time_point time;
    std::chrono::steady_clock::time_point time2;
    std::chrono::steady_clock::time_point time3;
    std::chrono::steady_clock::time_point time4;
    std::chrono::steady_clock::time_point time5;
    std::chrono::steady_clock::time_point time6;
    std::chrono::steady_clock::time_point time7;
    std::chrono::steady_clock::time_point time8;
    std::chrono::steady_clock::time_point time9;
    std::chrono::steady_clock::time_point time10;
    std::chrono::steady_clock::time_point time11;
    std::chrono::steady_clock::time_point time12;
    std::chrono::steady_clock::time_point time13;
    std::chrono::steady_clock::time_point time14;

    
    std::vector<int> v(10);
    std::generate(v.begin(), v.end(), random_integer);
    auto mySortProblem1 = SortIt_Using_Heap(v);
    time = std::chrono::high_resolution_clock::now();
    auto SortedList1 = (Sorted*) SortIt::solveRecursive(mySortProblem1);
    time2 = std::chrono::high_resolution_clock::now();
    microsec = std::chrono::duration_cast<std::chrono::microseconds>(time2 - time);
    std::cout << "List Sorted (Recursive)"<< SortedList1 << " Time Spent: " << (long long)microsec.count() << " microseconds\n";

    std::generate(v.begin(), v.end(), random_integer);
    auto mySortProblem2 = SortIt_Using_Heap(v);
    time3 = std::chrono::high_resolution_clock::now();
    auto SortedList2 = (Sorted*)SortIt::solveGreedy(mySortProblem2);
    time4 = std::chrono::high_resolution_clock::now();
    microsec2 = std::chrono::duration_cast<std::chrono::microseconds>(time4 - time3);
    std::cout << "List Sorted (Greedy)" << SortedList2 << " Time Spent: " << (long long)microsec2.count() << " microseconds\n";

  
    std::generate(v.begin(), v.end(), random_integer);
    auto mySortProblem3 = SortIt_Using_Heap(v);
    time5 = std::chrono::high_resolution_clock::now();
    auto SortedList3 = (Sorted*)SortIt::solveDivideAndConquer(mySortProblem3);
    time6 = std::chrono::high_resolution_clock::now();
    microsec3 = std::chrono::duration_cast<std::chrono::microseconds>(time6 - time5);
    std::cout << "List Sorted (Divide and Conquer)" << SortedList3 << " Time Spent: " << (long long)microsec3.count() << " microseconds\n";

    std::vector<int> v2(5);
    std::generate(v2.begin(), v2.end(), random_integer);
    auto mySortProblem4 = SortIt_Using_Heap(v2);
    time7 = std::chrono::high_resolution_clock::now();
    auto SortedList4 = (Sorted*)SortIt::solveLasVegas(mySortProblem4);
    time8 = std::chrono::high_resolution_clock::now();
    microsec4 = std::chrono::duration_cast<std::chrono::microseconds>(time8 - time7);
    std::cout << "List Sorted (Las Vegas)" << SortedList4 << " Time Spent: " << (long long)microsec4.count() << " microseconds\n";

    std::generate(v.begin(), v.end(), random_integer);
    auto mySSProblem = createSSProblem(v);
    time9 = std::chrono::high_resolution_clock::now();
    auto mySSSolution = (SearchAndSortSolution*)SearchAndSortProblem::heapSort(mySSProblem);
    time10 = std::chrono::high_resolution_clock::now();
    microsec5 = std::chrono::duration_cast<std::chrono::microseconds>(time10 - time9);
    std::cout << "\n\n SearchAndSortProblem methods: \n\n";
    std::cout << "List Sorted (Heap Sort)" << mySSSolution << " Time Spent: " << (long long)microsec5.count() << " microseconds\n";


    std::generate(v.begin(), v.end(), random_integer);
    auto mySSProblem3 = createSSProblem(v);
    time11 = std::chrono::high_resolution_clock::now();
    auto mySSSolution3 = (SearchAndSortSolution*)SearchAndSortProblem::mergeSort(mySSProblem3);
    time12 = std::chrono::high_resolution_clock::now();
    microsec6 = std::chrono::duration_cast<std::chrono::microseconds>(time12 - time11);
    std::cout << "List Sorted (Merge Sort)" << mySSSolution3 << " Time Spent: " << (long long)microsec6.count() << " microseconds\n";

    std::generate(v.begin(), v.end(), random_integer);
    auto mySSProblem4 = createSSProblem(v);
    time13 = std::chrono::high_resolution_clock::now();
    auto mySSSolution4 = (SearchAndSortSolution*)SearchAndSortProblem::quickSort(mySSProblem4);
    time14 = std::chrono::high_resolution_clock::now();
    microsec7 = std::chrono::duration_cast<std::chrono::microseconds>(time14 - time13);
    std::cout << "List Sorted (Quick Sort)" << mySSSolution4 << " Time Spent: " << (long long)microsec7.count() << " microseconds\n";

    
}

