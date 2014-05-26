#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Matrix.h"
#include <sys/timeb.h>
#include <sys/time.h>
#include "DijkstraSolution.h"

using namespace std;

void splitString(vector<string>* out, string str, string delimiter);

int main(int argc, const char * argv[])
{
    int n = 5;
    Graph g(n);
    g.connect(0, 1, 1);
    g.connect(1, 2, 1);
    g.connect(2, 3, 1);
    g.connect(3, 4, 1);
    Dijkstra dijsktra;
    DijkstraSolution sol(n);
    dijsktra.findPath(&g, 0, &sol);
    list<Edge*> path;
    sol.getPath(4, &path);
    for (auto it = begin(path); it != end(path); ++it) {
        cout << (*it)->fromNode << " -> " << (*it)->toNode << endl;
    }
    
    return 0;
}