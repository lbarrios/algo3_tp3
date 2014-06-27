#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import os
import numpy as np
from glob import glob
from collections import defaultdict

def make_listdict():
  return defaultdict(list)

def make_listdictdict():
  return defaultdict(make_listdict)

tests = defaultdict(make_listdictdict)

MMM = 1

cota_teorica_x = list()
cota_teorica_y = list()

cota_teorica = list()

files = sorted(glob("../output/local_search/*.txt.calidad"))
for f in files:
  file = open(f)
  filename = f.split("/")[-1]
  testname = filename.split("_")[0]
  (x, n, m, k) = [int(s[1:]) for s in filename.split(".")[0].split("_")[1:] ]
  testsize = n+m
  #print testsize
  cota_teorica_x.append(testsize)
  cota_teorica_y.append(k)
  cota_teorica.append( (testsize, float( k/MMM ) ) )
  print "x={}, n={}, m={}, k={}; tam_entrada={}".format(x,n,m,k,testsize)
  for line in file:
    if len(line.split())<2:
      continue
    #testtype = line.split()[0]
    testtype = "Promedio"
    value = line.split()[1]
    x = int(testsize)
    #if x < 40: continue  # esto es muy arbitrario 
    y = float( int(value) - k + (k/MMM) )
    tests[testname][testtype][x].append(y)
  file.close()

cota_teorica.sort()

tests_mean_xy = defaultdict(make_listdict)
tests_mean_p_xy = defaultdict(make_listdict)
for testname in tests:
  for testtype in tests[testname]:
    for testsize in tests[testname][testtype]:
      y_values = tests[testname][testtype][testsize]
      y_p_values = [yp for yp in y_values if yp < np.percentile(y_values,75) and yp > np.percentile(y_values,25) ]
      y_p_values = [yp for yp in y_values ]
      y_p_values_min = [yp for yp in y_values if yp == np.min(y_values) ]
      y_p_values_max = [yp for yp in y_values if yp == np.max(y_values) ]
      #y_p_values = [yp for yp in y_values if yp == np.min(y_values)]
      # -
      x = testsize
      y = float( np.mean( y_values ) )
      y_p = float( np.mean( y_p_values ) )
      y_p_min = float( np.mean( y_p_values_min ) )
      y_p_max = float( np.mean( y_p_values_max ) )
      # -
      tests_mean_xy[testname][testtype].append( (x,y) )
      tests_mean_p_xy[testname][testtype].append( (x,y_p) )
      tests_mean_p_xy["Minimo"]["Minimo"].append( (x,y_p_min) )
      tests_mean_p_xy["Maximo"]["Maximo"].append( (x,y_p_max) )
    tests_mean_xy[testname][testtype].sort()
    tests_mean_p_xy[testname][testtype].sort()
    tests_mean_p_xy["Minimo"]["Minimo"].sort()
    tests_mean_p_xy["Maximo"]["Maximo"].sort()

t_names = len(tests_mean_p_xy)
t_types = len(tests_mean_p_xy[testname])

colors = ['blue','green','red','cyan','magenta','yellow','black','grey','white']


import matplotlib.pyplot as plt
import matplotlib.ticker as tck
from time import strftime
# - Arreglo la columna tiempo
formatter = tck.EngFormatter(unit='', places=1) # Formato "segundos"
formatter.ENG_PREFIXES[-6] = 'u' # Arreglo el símbolo "mu"
# - Creo los subplot
#fig, subplot = plt.subplots(nrows=t_types, ncols=1, sharex=True, sharey=False)
fig,subplot = plt.subplots()
subplot.yaxis.set_major_formatter(formatter)

# Aplico formato
plt.grid(True)
plt.title(u"Búsqueda local (densidad media)")
plt.ylabel('Omega 2')
plt.xlabel(u'Tamaño de entrada (n + m)')

"""
linestyle or ls [ ‘-‘ | ‘--’ | '.' | ‘-.’ | ‘:’ | ‘steps’ | ...]
marker  [ ‘+’ | ‘,’ | ‘.’ | ‘1’ | ‘2’ | ‘3’ | ‘4’ ]
"""

# ploteo datos
for test_number in range(0,t_names):
  testname = tests_mean_p_xy.keys()[test_number]
  testtype = tests_mean_p_xy[testname].keys()[0]#[int(i/t_names)]
  #x = np.array( zip(*tests_mean_xy[testname][testtype])[0] )
  #y = np.array( zip(*tests_mean_xy[testname][testtype])[1] )
  #plt.plot(x, y, linestyle='-',  color=colors[test_number], linewidth=0.2, label=testname, alpha=1)
  x = np.array( zip(*tests_mean_p_xy[testname][testtype])[0] )
  y = np.array( zip(*tests_mean_p_xy[testname][testtype])[1] )
  print testtype
  print x
  print y
  plt.plot(x, y, linestyle='-',  color=colors[test_number], linewidth=1, label=testtype, alpha=1) #, marker='.', markersize=0.3)

t_x = np.array( [x for (x,y) in cota_teorica] )
t_y = np.array( [y for (x,y) in cota_teorica] )
# ploteo cota teórica
print t_x
print t_y
subplot.plot(t_x, t_y,    '--', color='black', linewidth=2, label="Optima")
plt.legend(loc=2)
plt.tight_layout()  # para que entren las labels
plt.xlim(xmax=3000)
plt.ylim(ymin=15,ymax=500)

#plt.show()
if not os.path.exists('../graficos/') or not os.path.isdir('../graficos/'):
  os.makedirs('../graficos/')
from datetime import datetime
plt.savefig("../graficos/calidad_local_search_{}.pdf".format(datetime.now().strftime("%Y-%m-%d_%H-%M-%S")))

