#!/usr/bin
import sys
import os 
import matplotlib.pyplot as plt

input_base = '../input/'
output_base = '../output/'

if len(sys.argv) < 2: 
	raise "Falta el input"

input = sys.argv[1]
input_full = input_base + input

f = open(input_full)
K = f.readlines()[0].split(" ")[4]
f.close()
	

bins = [
	{
	'name' : 'backtracking',
	'bin' : '../backtracking/backtracking'
	},
	{
	'name' : 'greedy_A',
	'bin' : "../greedy_heuristic_A/greedy_heuristic_A"
	},
	{
	'name' : 'greedy_B',
	'bin' : "../greedy_heuristic_B/greedy_heuristic_B"
	},
	{
	'name' : 'greedy_C',
	'bin' : "../greedy_heuristic_C/greedy_heuristic_C"
	},
	{
	'name' : 'local_search',
	'bin' : "../local_search/local_search"
	},
	{
	'name' : 'grasp',
	'bin' : "../grasp/grasp"
	},
]

omega1 = []
omega2 = []

# calculo los resultados de los problemas
for bin in bins:
	#input='random_x1_n20_m29_k132.txt'
	output=bin['name']+"_"+input
	bin['output'] = output_base+output
	
	command = "{} < {} > {}".format(bin['bin'],input_full,bin['output'])
	print("Running:",command)
	os.system(command)

	f = open(bin['output'])
	lines = f.readlines()
	f.close()

	(w1, w2) = lines[0].split(" ")[0:2]

	omega1.append({ 'H' : bin['name'], 'value' : w1 })
	omega2.append({ 'H' : bin['name'], 'value' : w2 })

# graficos los resultados
K_line = [K for i in omega1]

omega1_xaxis = [i['H'] for i in omega1]
omega1_yaxis = [int(i['value']) for i in omega1]

omega2_xaxis = [i['H'] for i in omega2]
omega2_yaxis = [int(i['value']) for i in omega2]

# Two subplots, the axes array is 1-d
f, axarr = plt.subplots(2, sharex=True)
axarr[0].plot(range(len(omega1_xaxis)), K_line, 'r')
axarr[0].bar(range(len(omega1_yaxis)), omega1_yaxis, align='center')
axarr[0].set_title('Omega1')
axarr[1].bar(range(len(omega2_yaxis)), omega2_yaxis, align='center')
axarr[1].set_title('Omega2')

plt.xticks(range(len(omega1_yaxis)), omega1_xaxis, size='small')
plt.show()
