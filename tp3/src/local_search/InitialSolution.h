#pragma once

#include "Solution.h"
#include "../common/ProblemInstance.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraSolution.h"

class InitialSolution
{
public:
  InitialSolution();
  virtual ~InitialSolution() = default;
  virtual Solution* getInitialSolution(ProblemInstance* instance) = 0;

};