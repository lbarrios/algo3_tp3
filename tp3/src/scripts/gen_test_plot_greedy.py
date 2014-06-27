import subprocess

instancias = "20"

for n in range(5, 110):
    m = (n*(n-1))/4
    subprocess.call(["python", "createInput_magic.py", instancias, str(n), str(m)])

greedy = "A"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "magic"])

greedy = "B"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "magic"])

greedy = "C"
subprocess.call(["python", "correrTestTiempoGreedy.py", "greedy_heuristic_%s"%(greedy), "magic"])


subprocess.call(["python", "graficar_greedy.py", greedy])
