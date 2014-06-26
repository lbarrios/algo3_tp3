#pragma once

#include <vector>
#include <iostream>
#include "Edge.h"

using namespace std;

class Solution
{
public:
	Solution() = default;	
	~Solution() = default;

	double totalOmega1;
  	double totalOmega2;
  	vector<Edge*> path;  	

    Solution* createSubSolutionBetween(int node1, int node2) const;
    void print();
};