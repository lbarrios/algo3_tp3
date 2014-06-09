#include "NeighbourhoodSelectorA.h"

Solution* NeighbourhoodSelectorA::getBestNeighbour(Solution* solution)
{	
	Solution* bestSolution = solution;		
	/*for ( list<Edge*>::iterator it1 = begin(solution->path); it1 != end(solution->path); ++it1 ) {
    	double omega1Sum = 0;
    	list<Edge*>::iterator it2 = begin(solution->path);
     	for (std::advance(it2, ) ; it2 != end(solution->path); ++it2 ) {
     		if(*it1 == *it2) continue;
       		 omega1Sum += (*it1)->omega1;

       		 Solution* path = &(pathMatrix[(i-1)+ (j-1) * nodeCount]);
      	}
    }*/
    return bestSolution;
}

