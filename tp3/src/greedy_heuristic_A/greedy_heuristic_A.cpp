#include <iostream>
#include "../common/GreedyHeuristic.h"
#include "../common/Dijkstra.h"
#include "../common/ObjectiveFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
	int take_time = 0;
	int iters = 50;
	string save2file = "time_greedy_a.txt";

	if( argc > 1 ) take_time = atoi( argv[1] );
	if( argc > 2 ) iters = atoi( argv[2] );
	if( argc > 3 ) save2file = argv[3];

	cout << take_time << " " << iters << " " << save2file << endl;

	GreedyHeuristic<ObjectiveFunctionA> greedy(take_time, iters, save2file);
	greedy.run();	
    
    return 0;
}
