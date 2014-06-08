#pragma once

#include "Solution.h"

class InitialSolution
{
public:
  InitialSolution() = default;
  ~InitialSolution() = default;
  virtual Solution getInitialSolution();
};