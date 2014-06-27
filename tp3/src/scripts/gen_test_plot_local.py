#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/local_search/*")

n = 6
while n<200:
    if n<50:
       n += 1
    elif n<80:
       n += 2
    elif n<110:
       n += 4
    else:
       n += 10
    m = (n*(n-1))/2
    #m = int(math.sqrt(n))*n
    #m = 10*n
    subprocess.call(["python", "createInput_magic.py", "20", str(n), str(m)])

subprocess.call(["python3", "correrTestCalidad.py", "local_search", "magic"])
subprocess.call(["python", "graficar_local_search_calidad.py"])
