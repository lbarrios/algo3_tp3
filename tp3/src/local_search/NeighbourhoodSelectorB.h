#pragma once

#include "NeighbourhoodSelector.h"

class NeighbourhoodSelectorB : public NeighbourhoodSelector
{
public:
	Solution* getBestNeighbour(Solution* solution);
};