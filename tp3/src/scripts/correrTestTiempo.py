#!/usr/bin/env python3
from glob import glob
import os
import sys

# redefino la señal de interrupción
import signal
import sys
def signal_handler(signal, frame):
        print('You pressed Ctrl+C!')
        sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)

# chequeo si existe la carpeta de output, si no la creo
if not os.path.exists("../output/") or not os.path.isdir("../output/"):
    os.makedirs("../output/")

# parseo tipo de heuristica
try:
    heuristic = sys.argv[1]
except:
    print("Error: Debe ingresar el nombre de la heurística como primer parámetro.")
    print("Ejemplo: greedy_heuristic_A, local_search, backtracking")
    quit()
# me fijo si el directorio y el binario de la heuristica existe
heuristic_path = "../{}/".format(heuristic)
if not os.path.exists(heuristic_path) or not os.path.isdir(heuristic_path):
    print("Error: El parámetro ingresado '{}' no se reconoce como una heurística válida.".format(heuristic))
    quit()
heuristic_bin = "{}{}.time".format(heuristic_path,heuristic)
if not os.path.exists(heuristic_bin) or not os.path.isfile(heuristic_bin):
    print("Error: Se encontró la carpeta '{}' pero no se encuentra el ejecutable '{}', por favor asegurarse de que esté compilado".format(heuristic_path,heuristic_bin))
    quit()
# parseo tipo de input
try:
    tipo_de_input = sys.argv[2]
except:
    print("Error: Debe ingresar el tipo de input como segundo parámetro.")
    quit()
# me fijo si existen inputs con ese prefijo
inputFiles = glob("../input/{}_*.txt".format(tipo_de_input))
if not inputFiles:
    print("Error: No se encontraron input con el prefijo '{}' ingresado".format(tipo_de_input))
    quit()

for input in sorted(inputFiles):
    output = input.replace("input","output/backtracking")
    if not os.path.exists("../output/backtracking") or not os.path.isdir("../output/backtracking"):
        os.makedirs("../output/backtracking")
    command = "{} < {} > {}".format(heuristic_bin,input,output)
    print("Running:",command)
    os.system(command)
