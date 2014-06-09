#pragma once

#include <vector>
#include <iostream>
#include "../common/Edge.h"

using namespace std;

class Solution
{
public:
	Solution() = default;
	~Solution() = default;

	double totalOmega1;
  	double totalOmega2;
  	vector<Edge*> path;

  	bool operator == (const Solution &other) const;
    bool operator < (const Solution &other) const;
    bool operator > (const Solution &other) const;
};