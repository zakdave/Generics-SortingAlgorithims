#pragma once
#include "Problem.h"
#include <algorithm>
#include <vector>
#include <execution>
#include <iostream>


class aSolution * Problem::solveDivideAndConquer(class Problem * aProblem) {
	if (aProblem->trivial()) 
		return aProblem->createSolution();
	
	auto subProblems = aProblem->make_subproblems();
	// transform and collect the solutions to the subProblems
	std::vector<aSolution *> partialSoutions(subProblems.size());
	std::transform(
		subProblems.begin(), subProblems.end(),
		partialSoutions.begin(), solveDivideAndConquer);
	// combine the subProblems into a single solution
	return aProblem->combineSolutions(partialSoutions);
}

class aSolution * Problem::solveLasVegas(class Problem * aProblem) {
	//select a random action, refine the problem while it is not solved
	// in this case a new Problem is not returned, the current problem is modified.
	while (!aProblem->solved()) {
		aProblem = aProblem->applyRandomAction();
	}
	return aProblem->createSolution();
}


class aSolution * Problem::solveGreedy(class Problem * aProblem){
	// while not solved apply the next best known action and update the problem.
	
	while (!aProblem->solved()) {
		aProblem = aProblem->applyBestAction();
		// apply best action method here
	}
	return aProblem->createSolution();
}
class aSolution * Problem::solveRecursive(class Problem * aProblem) {
	if (aProblem->trivial())
		return aProblem->createSolution();
	auto newProblem = aProblem->simplifyProblem();
	return Problem::solveRecursive(newProblem);
}
