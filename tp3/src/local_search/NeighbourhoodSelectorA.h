#pragma once

#include "NeighbourhoodSelector.h"

class NeighbourhoodSelectorA : public NeighbourhoodSelector
{
public:
	Solution* getBestNeighbour(Solution* solution);
};