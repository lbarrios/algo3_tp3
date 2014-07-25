#pragma once

#include "NeighbourhoodSelector.h"

class NeighbourhoodSelectorA : public NeighbourhoodSelector
{
	Solution* removeCycles(Solution* solution);
public:
	Solution* getBestNeighbour(const Solution* solution);
};