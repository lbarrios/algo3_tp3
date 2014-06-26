import subprocess

for m in range(20, 40):
    subprocess.call(["python", "createInput_random_backtracking.py", "10", 15, str(m)])

subprocess.call(["python3", "correrTestTiempo.py", "backtracking", "random"])
subprocess.call(["python", "graficar_backtracking.py"])
