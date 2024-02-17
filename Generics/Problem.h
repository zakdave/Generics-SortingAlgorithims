#pragma once
#include <vector>
#include "aSolution.h"

class Problem
{
public:
	virtual bool trivial() = 0;
	virtual bool solved() = 0;
	virtual bool better(class Problem * Reference) = 0;
	virtual std::vector<Problem *> make_subproblems()=0;
	virtual class aSolution * createSolution() = 0;
	virtual class aSolution * combineSolutions(std::vector<aSolution *> partialSolutions) = 0; // in paper this is combine
	virtual class Problem * simplifyProblem()=0;  // in paper this is called refine
	virtual class Problem* applyBestAction() = 0;
	virtual class Problem* applyRandomAction() = 0;
	

	static class aSolution * solveDivideAndConquer(class Problem *);
	static class aSolution * solveLasVegas(class Problem *);
	static class aSolution * solveGreedy(class Problem *);
	static class aSolution * solveRecursive(class Problem *);
	
};

