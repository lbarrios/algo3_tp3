#!/usr/bin/env python

import subprocess
import os
import math
from datetime import datetime

os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/local_search/*")

n = 6
while n<20:
    n = n + 1
    #m = (n*(n-1))/2
    #m = int(math.sqrt(n))*n
    #m = 10*n
    subprocess.call(["python", "createInput_random.py", "1", str(n)])
