#pragma once

#include <list>
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
  	list<Edge*> path;

  	bool operator == (const Solution &other) const;
    bool operator < (const Solution &other) const;
    bool operator > (const Solution &other) const;
};