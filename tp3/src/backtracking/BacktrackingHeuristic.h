#pragma once

#include "BacktrackingHeuristic.h"
#include "../common/Graph.h"
#include "../common/Dijkstra.h"
#include "../common/DijkstraSolution.h"
#include "../common/ObjectiveFunctions.h"

#define INFINITE 1<<30

class BacktrackingHeuristic {
private:
    struct Solution {
        vector<Node> path;
        int totalOmega1 = 0;
        int totalOmega2 = 0;
    };
    double *distancesOmega1;
    double *distancesOmega2;
    vector<bool> visited;
    Solution currentBranch;
public:
    //BacktrackingHeuristic();
    void parseInput(int);
    void initialize();
    void backtrack(Edge*);
    void printSolution();
    int N, M, U, V, K;
    Graph *G;
    Solution bestSolutionFound;
};
