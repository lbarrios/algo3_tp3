import subprocess

for n in range(3, 14):
    for i in range(20):
        subprocess.call(["python", "createInput_random_backtracking.py", "10", str(n)])

subprocess.call(["python3", "correrTestTiempo.py", "backtracking", "random"])
subprocess.call(["python", "graficar_backtracking.py"])
