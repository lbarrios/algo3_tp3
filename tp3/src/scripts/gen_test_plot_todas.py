#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

#os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
#os.system("rm ../input/*")
#os.system("rm ../output/*/*")

n = 5
while n<30:
    n += 1
    m = (n*(n-1))/4 # notar que hay un 4, no un 2
    #m = int(math.sqrt(n))*n
    #m = 10*n
    print n
    os.system("python createInput_magic.py 40 %d %d" % (n, m))

os.system("./correrTestCalidad.py backtracking magic")
os.system("./correrTestCalidad.py greedy_heuristic_All magic")
os.system("./correrTestCalidad.py grasp magic")
os.system("./correrTestCalidad.py local_search magic")

subprocess.call(["python", "graficar_todos.py"])


#os.system("epdfview `ls -t ../graficos | head -n 1`")
