#pragma once

#include "NeighbourhoodSelector.h"

class NeighbourhoodSelectorC : public NeighbourhoodSelector
{
public:
	Solution* getBestNeighbour(Solution* solution);
};