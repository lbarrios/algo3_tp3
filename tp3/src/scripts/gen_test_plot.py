import subprocess

for n in range(5, 25):
    for i in range(15):
        subprocess.call("python createInput_magic.py 5 %d" % n, shell=True)

subprocess.call("python3 correrTestTiempo.py backtracking magic", shell=True)
subprocess.call("python graficar_backtracking.py", shell=True)
