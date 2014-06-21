#include <iostream>
#include "../common/GreedyHeuristic.h"
#include "../common/Dijkstra.h"
#include "../common/ObjectiveFunctions.h"

using namespace std;

int main()
{
	GreedyHeuristic<ObjectiveFunctionA> greedy;
	greedy.run();	
    
    return 0;
}
