#include "NeighbourhoodSelectorB.h"

Solution* NeighbourhoodSelectorB::getBestNeighbour(Solution* solution)
{	
    for(int j=1; j<=nodeCount; j++) {
      for(int k=1; k<=nodeCount; k++) {        
        Solution sPath = pathMatrix[(j-1)+ (k-1) * nodeCount];
        /*cout << j << " -> " << k << ": ";
        cout << "Omega1: " << sPath.totalOmega1 << ", Omega2: " << sPath.totalOmega2 << endl;
        cout << "Path: ";
        for ( auto it = begin( sPath.path ); it != end( sPath.path ); ++it )
        {
          cout << ( *it )->fromNode << " -> " << ( *it )->toNode << ", ";
        }
        cout << endl << endl;*/
      }
    }
    return NULL;
}

