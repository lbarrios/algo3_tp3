#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

os.system("tar czf ../backup/grasp_%s.tar.gz ../input ../output/grasp" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/grasp/*")

n = 15
while n<200:
    if n<50:
       n += 4
    elif n<80:
       n += 8
    elif n<110:
       n += 11
    else:
       n += 30
    #m = (n*(n-1))/2
    m = int(math.sqrt(n))*n
    #m = 10*n
    subprocess.call(["python", "createInput_magic.py", "20", str(n), str(m)])

subprocess.call(["python3", "correrTestCalidad.py", "grasp", "magic"])
subprocess.call(["python", "graficar_grasp_calidad.py"])
