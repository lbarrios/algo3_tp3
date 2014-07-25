#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

#os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/local_search/*")

for n in range(10, 500, 10):
  m = int(n*math.sqrt(n))
  subprocess.call(["python", "createInput_magic.py", "15", str(n), str(m)])

#n = 50
#m = 50-1
#while m<(n*(n-1))/2:
    #m += n
    #m = 10*n
    #subprocess.call(["python", "createInput_magic.py", "100", str(n), str(m)])

subprocess.call(["python", "correrTestCalidad.py", "local_search", "magic"])
subprocess.call(["python", "graficar_local_search_iteraciones.py"])
