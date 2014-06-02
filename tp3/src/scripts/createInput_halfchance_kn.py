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

for r in range(0, instanceCount):
    nMin = 10
    nMax = 100        
    kMult = 10
    #defino el nombre de cada archivo    
    n = randint(nMin, nMax) # Cantidad de nodos
    m = (n-1) * n / 2 # Cantidad de aristas
    u = randint(1, n) # Nodo inicial
    v = u  # nodo final, debe ser distinto de u  
    while(u == v):
        v = randint(1, n)    
    K = randint(nMin * kMult, nMax * kMult) # cota para omega1(uso un rango igual al rango de n por 10)
    
    fo.write(str(n) + " " + str(m) + " " + str(u) + " " + str(v) + " " + str(K) + "\n")
    #para cada pueblo genero su coordenada x y 
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            chance = randint(1, 2)
            if chance == 1:
                v1 = i
                v2 = j
                w1 = randint(1, kMult)
                w2 = randint(1, kMult)
                fo.write(str(v1) + " " + str(v2) + " " + str(w1) + " " + str(w2) + "\n")
    #ultima linea es un 0 y cierro el archivo    
    if r == instanceCount-1:
        fo.write("0")
fo.close()


