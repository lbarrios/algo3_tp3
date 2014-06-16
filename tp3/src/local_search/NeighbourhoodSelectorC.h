#pragma once

#include "NeighbourhoodSelector.h"

class NeighbourhoodSelectorC : public NeighbourhoodSelector
{
public:
	Solution* getBestNeighbour(const Solution* solution);
};