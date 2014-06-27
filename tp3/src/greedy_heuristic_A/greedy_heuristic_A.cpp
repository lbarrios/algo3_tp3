#include <iostream>
#include "../common/GreedyHeuristic.h"
#include "../common/Dijkstra.h"
#include "../common/ObjectiveFunctions.h"
#include "../common/Timer.h"

using namespace std;

int main(int argc, char* argv[])
{
	Timer timer(cerr);
	GreedyHeuristic<ObjectiveFunctionA> greedy(&timer);
	greedy.run();	
    
    return 0;
}
