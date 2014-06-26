#! /usr/bin/env python
SCALE = 100
SCALE_DEVIATION = 10

import sys
from random import randint
import math


def add_edges_recursive(fromNode, toNode):
    diff = toNode - fromNode
    lower_bound = SCALE * diff - P * SCALE_DEVIATION
    upper_bound = SCALE * diff + P * SCALE_DEVIATION
    omega1 = randint(lower_bound, upper_bound)
    omega2 = randint(lower_bound, upper_bound)
    debugEdge = "%d %d %d %d\n" % (fromNode, toNode, omega1, omega2)
    fo.write(debugEdge)
    m = fromNode + diff/2
    if fromNode != toNode-1:
        add_edges_recursive(fromNode, m)
        add_edges_recursive(m, toNode)


# argumentos opcionales
instanceCount = -1
P = -1

if len(sys.argv) > 1:
    instanceCount = int(sys.argv[1])
    if len(sys.argv) > 2:
        P = int(sys.argv[2])

print "Se llamo a script con parametros:"
print "createInput_sandwich instanceCount: %d p:%d" % (instanceCount, P)

if instanceCount == -1:
    instanceCount = 1
if P == -1:
    P = 3

N = math.pow(2, P) + 1
M = math.pow(2, P+1) - 1
K = math.pow(2, P) * SCALE

fo = open("../input/sandwich_x%d_n%d_m%d_k%d_p%d.txt" % (instanceCount, N, M, K, P), "wb")

U = 1
V = N
header = "%d %d %d %d %d\n" % (N, M, U, V, K)
print header

for r in range(0, instanceCount):
    fo.write(header)
    add_edges_recursive(1, N)

fo.write("0")
fo.close()
