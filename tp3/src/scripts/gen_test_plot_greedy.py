import subprocess

instancias = "20"

for n in range(3, 10):
    for i in range(20):
        subprocess.call(["python", "createInput_random_greedy.py", instancias, str(n)])

greedy = "A"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "random"])
subprocess.call(["python", "graficar_greedy.py", greedy])

greedy = "B"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "random"])
subprocess.call(["python", "graficar_greedy.py", greedy])

greedy = "C"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "random"])
subprocess.call(["python", "graficar_greedy.py", greedy])
