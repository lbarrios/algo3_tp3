#include <iostream>
#include "../common/Timer.h"
#include "GreedyHeuristicAll.h"

using namespace std;

int main(int argc, char* argv[])
{
	Timer timer(cerr);
	GreedyHeuristicAll greedy(&timer);
	greedy.run();	
    
    return 0;
}
