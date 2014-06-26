# graficar para n de 10 a 17 y m fijo

import subprocess

for n in range(10, 24):
    for i in range(10):
        subprocess.call(["python", "createInput_random_backtracking.py", "10", str(n), "40"])

subprocess.call(["python3", "correrTestTiempo.py", "backtracking", "random"])
subprocess.call(["python", "graficar_backtracking.py"])
