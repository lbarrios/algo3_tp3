#! /usr/bin/env python

import sys
from random import randint

instanceCount = 1
if len(sys.argv) > 1:
    file_id = int(sys.argv[1])
    if len(sys.argv) > 2:
        instanceCount = int(sys.argv[2])
else:
    file_id = 0    

print "Se llamo a script con parametros:"
print "createInput_kn " + str(file_id) + " " + str(instanceCount) + " (file_id, instanceCount)"

fo = open("../input/hckn_" + str(file_id) + ".txt", "wb")

forcedN = -1
if len(sys.argv) > 3:
    forcedN = int(sys.argv[3])

for r in range(0, instanceCount):
    if forcedN != -1:
        nMin = forcedN
        nMax = forcedN
    else:
        nMin = 10
        nMax = 100
    kMult = 10
    #defino el nombre de cada archivo    
    n = randint(nMin, nMax) # Cantidad de nodos
    m = int(((n-1) * n / 2) / 2) # Cantidad de aristas(uso la mitad de un Kn)
    u = randint(1, n) # Nodo inicial
    v = u  # nodo final, debe ser distinto de u  
    while(u == v):
        v = randint(1, n)    
    K = randint(nMin * kMult, nMax * kMult) # cota para omega1(uso un rango igual al rango de n por 10)
    
    fo.write(str(n) + " " + str(m) + " " + str(u) + " " + str(v) + " " + str(K) + "\n")
    # escribo los ejes
    addedEdges = 0 # todo lo que sigue es muuyyy feo :P
    neighbours = []
    for i in range(0, n):
        neighbours.append([])
    while addedEdges < m:
        for i in range(1, n+1):
            for j in range(i+1, n+1):
                chance = randint(1, 2)
                try:
                    neighbours[i-1].index(j)
                except:
                    if chance == 1 and addedEdges < m:
                        v1 = i
                        v2 = j
                        w1 = randint(1, kMult)
                        w2 = randint(1, kMult)
                        fo.write(str(v1) + " " + str(v2) + " " + str(w1) + " " + str(w2) + "\n")
                        addedEdges += 1
                        neighbours[i-1].append(j)


    #ultima linea es un 0 y cierro el archivo
    if r == instanceCount-1:
        fo.write("0")
fo.close()


