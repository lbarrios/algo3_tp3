//
//  Node.cpp
//  Ej3TP2
//
//  Created by Jonathan Melnik on 4/18/14.
//  Copyright (c) 2014 ___JonathanMelnik___. All rights reserved.
//

#include "Node.h"
#include "PreviousNode.h"

Node::Node(int row, int col, int jumpPower)
{
    this->row = row;
    this->col = col;
    this->jumpPower = jumpPower;
}

void Node::connectToNextNode(Node* node, int powerUsed, int kUsed) {
    edgesToNextNodes.push_back(new Arrow(node, powerUsed, kUsed));
}

Node::~Node() {
    for (int i=0; i<edgesToNextNodes.size(); i++) {
        delete edgesToNextNodes[i];
    }
    for (int i=0; i<prevNodes.size(); i++) {
        delete prevNodes[i];
    }
}