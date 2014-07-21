#! /usr/bin/env python
SCALE = 1000

import sys
from random import randint
import math

if len(sys.argv) < 4:
    raise Exception("parametros obligatorios: instanceCount, N, M")

instanceCount = int(sys.argv[1])
N = int(sys.argv[2])
M = int(sys.argv[3])
if M < N-1:
    raise Exception("M debe ser por lo menos N-1 para hacer el camino inicial")
U = 1
V = N
K = (N-1)

print "Se llamo a script con parametros:"
print "createInput_magic instanceCount: %d n:%d m%d" % (instanceCount, N, M)
fo = open("../input/magic_x%d_n%d_m%d_k%d.txt" % (instanceCount, N, M, K), "wb")

header = "%d %d %d %d %d\n" % (N, M, U, V, K)
print header


for r in range(instanceCount):
    fo.write(header)

    adjacent = []
    for i in range(N):
        adjacent.append([i])  # para que no haya loops

    for i in range(N-1):
        adjacent[i].append(i+1)
        debugEdge = "%d %d %d %d\n" % (i+1, i+2, 1, 1)
        fo.write(debugEdge)

    addedEdges = N-1
    while (addedEdges < M):
        fromNode = randint(0, N-1)
        toNode = randint(0, N-1)
        if (fromNode > toNode): continue
        try:
            adjacent[fromNode].index(toNode)
        except:
            adjacent[fromNode].append(toNode)
            adjacent[toNode].append(fromNode)
            fromNode += 1  # corrijo para la indexacion empezando en 1 
            toNode += 1
            diff = toNode - fromNode
            lower_bound = 0 
            upper_bound = 2*diff
            omega1 = randint(lower_bound, upper_bound)
            omega2 = diff + diff - omega1
            #omega2 = randint(lower_bound, upper_bound)
            debugEdge = "%d %d %d %d\n" % (fromNode, toNode, omega1, omega2)
            fo.write(debugEdge)
            addedEdges += 1

fo.write("0")
fo.close()
