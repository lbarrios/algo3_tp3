#include <iostream>
#include <vector>
#include "BacktrackingHeuristic.h"
#include "../common/Timer.h"

Timer timer( cerr );

int main() {
    int N;
    while (cin >> N && N) {
        BacktrackingHeuristic b;
        b.parseInput(N);
        timer.setInitialTime( "todo_el_codigo" );
        
        if (b.U != b.V) {
            b.initialize();
            vector<Node> adjacent = b.G->getAdjacent(b.U); // se devuelve por referencia
            for (int i = 0; i < adjacent.size(); i++) {
                Node n = adjacent[i];
                Edge *f = b.G->getEdge(b.U, n);
                b.backtrack(f);
            }
        }
        
        timer.setFinalTime( "todo_el_codigo" );
        timer.saveAllTimes();
        b.printSolution();
    }
    return 0;
}
