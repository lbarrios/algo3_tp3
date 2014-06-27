#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

#os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/*/*")

n = 3
while n<20:
    n = n + 1
    m = (n*(n-1))/2
    #m = int(math.sqrt(n))*n
    #m = 10*n
    subprocess.call(["python", "createInput_magic.py", "1", str(n), str(m)])

os.system("./correrTestCalidad.py backtracking magic")
os.system("./correrTestCalidad.py greedy_heuristic_A magic")
os.system("./correrTestCalidad.py greedy_heuristic_B magic")
os.system("./correrTestCalidad.py greedy_heuristic_C magic")
os.system("./correrTestCalidad.py grasp magic")
os.system("./correrTestCalidad.py local_search magic")

subprocess.call(["python", "graficar_todos.py"])


#os.system("epdfview `ls -t ../graficos | head -n 1`")
