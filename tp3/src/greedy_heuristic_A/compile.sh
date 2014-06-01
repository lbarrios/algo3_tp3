#!/usr/bin/env bash

g++ greedy_heuristic_A.cpp ../common/Parser.cpp ../common/ProblemInstance.cpp ../common/Graph.cpp ../common/Edge.cpp ../common/DijkstraSolution.cpp ../common/Dijkstra.cpp ../greedy_heuristic_common/GreedyHeuristic.cpp -o greedy_heuristic -std=c++11
