#include <iostream>
#include "../common/GreedyHeuristic.h"
#include "../common/Dijkstra.h"
#include "../common/ObjectiveFunctions.h"
#include "../common/Timer.h"

using namespace std;

int main()
{
	Timer timer(cerr);
	GreedyHeuristic<ObjectiveFunctionC> greedy(&timer);
	greedy.run();
  return 0;
}
