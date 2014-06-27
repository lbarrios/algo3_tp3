import subprocess

greedy = "C"
instancias = "20"

for n in range(3, 14):
    for i in range(20):
        subprocess.call(["python", "createInput_random_greedy.py", greedy, instancias, str(n)])

subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "random"])
subprocess.call(["python", "graficar_greedy.py", greedy])
