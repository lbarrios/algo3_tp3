#!/usr/bin/env python

import subprocess

for n in range(5, 25):
    if n < 20:
        for i in range(15):
            subprocess.call("python createInput_random.py 5 %d" % n, shell=True)
    else:
        for i in range(40):
            subprocess.call("python createInput_random.py 5 %d" % n, shell=True)

subprocess.call("python3 correrTestTiempo.py backtracking random", shell=True)
subprocess.call("python graficar_backtracking.py", shell=True)
