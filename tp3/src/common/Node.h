//
//  Node.h
//  Ej3TP2
//
//  Created by Jonathan Melnik on 4/18/14.
//  Copyright (c) 2014 ___JonathanMelnik___. All rights reserved.
//

#pragma once

#include <vector>
#include "Arrow.h"

using namespace std;

class PreviousNode;
class Edge;

class Node
{

public:
    int col;
    int row;
    int jumpPower;
    vector<Arrow*> prevNodes;
    vector<Arrow*> edgesToNextNodes;
    vector<int> jumpsSoFar;
    int maxKLeftSoFar;
    int minJumps;
    
    Node(int row, int col, int jumpPower);
    ~Node();
    
    void connectToNextNode(Node* node, int powerUsed, int kUsed);
};
