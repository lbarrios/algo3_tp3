#! /usr/bin/env python

import sys
from random import randint

# argumentos opcionales
instanceCount = -1
N = -1
M = -1
K = -1

if len(sys.argv) > 1:
    instanceCount = int(sys.argv[1])
    if len(sys.argv) > 2:
        N = int(sys.argv[2])
        if len(sys.argv) > 3:
            M = int(sys.argv[3])
            if len(sys.argv) > 4:
                K = int(sys.argv[4])


if instanceCount == -1:
    instanceCount = 1
if N == -1:
    N = 20
if M == -1:
    M = randint(N-1, N*(N-1)/2)
    #M = randint(0, N*(N-1)/2)
if K == -1:
    K = randint(N, 10*N)  # pensar

#print "createInput_random instanceCount: %d n:%d m:%d k:%d" % (instanceCount, N, M, K)
fo = open("../input/random_x%d_n%d_m%d_k%d.txt" % (instanceCount, N, M, K), "wb")

for r in range(0, instanceCount):
    U = randint(1, N) # Nodo inicial
    V = U  # nodo final, debe ser distinto de u  
    while(U == V):
        V = randint(1, N)
    
    header = "%d %d %d %d %d\n" % (N, M, U, V, K)
    #print header
    fo.write(header)

    # escribo los ejes
    neighbours = []
    for i in range(N):
        neighbours.append([])


    ## voy a armar el circuito c_n
    #for i in range(N-1):
    #    fo.write("%d %d %d %d\n" % (i+1, i+2, K/N, K/N))
    #    neighbours.append([i+1])
    #neighbours.append([])

    #added = N - 1
    added = 0
    while added < M:
        i = randint(1, N)
        j = i
        while(j == i):
            j = randint(1, N)
        try:
            neighbours[i-1].index(j-1)
        except:
            w1 = randint(K/(N*2), 2*K/N)  # la media es K/N
            w2 = randint(1, 2*K/N)
            debugEdge = "%d %d %d %d\n" % (i, j, w1, w2)
            #print debugEdge
            fo.write(debugEdge)
            neighbours[i-1].append(j-1)
            neighbours[j-1].append(i-1)
            added += 1

        #ultima linea es un 0 y cierro el archivo
        if r == instanceCount-1:
            fo.write("0")

fo.close()
