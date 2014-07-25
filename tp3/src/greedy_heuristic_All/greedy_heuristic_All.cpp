#include <iostream>
#include "GreedyHeuristicAll.h"
#include "../common/Timer.h"

using namespace std;

int main(int argc, char* argv[])
{
	Timer timer(cerr);
	GreedyHeuristicAll greedy(&timer);
	greedy.run();	
    
    return 0;
}
