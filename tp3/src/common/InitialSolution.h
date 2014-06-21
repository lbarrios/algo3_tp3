#pragma once

#include "../local_search/Solution.h"
#include "ProblemInstance.h"
#include "Dijkstra.h"
#include "DijkstraSolution.h"

class InitialSolution
{
public:
  InitialSolution();
  virtual ~InitialSolution() = default;
  virtual Solution* getInitialSolution(ProblemInstance* instance) = 0;

};