import subprocess
import os
from datetime import datetime

os.system("tar czf ../backup/local_search_%s.tar.gz ../input ../output/local_search" % datetime.now().strftime("%Y-%m-%d_%H_%M_%S"))
os.system("rm ../input/*")
os.system("rm ../output/local_search/*")

for n in range(5, 110):
    m = (n*(n-1))/4
    #m = int(math.sqrt(n))*n
    #m = 10*n
    subprocess.call(["python", "createInput_magic.py", "20", str(n), str(m)])

subprocess.call(["python3", "correrTestTiempo.py", "local_search", "magic"])
subprocess.call(["python", "graficar_local_search.py"])
