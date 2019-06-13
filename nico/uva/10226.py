# AC
import sys

t = int(sys.stdin.readline()[:-1])
sys.stdin.readline()

second = False

for _ in range(t):
	d, n_trees = {}, 0

	if second: print()
	while True:
		try:
			tree = sys.stdin.readline()[:-1]
			if tree == '': break
		except:
			break
		
		d[tree] = d.get(tree, 0) + 1
		n_trees += 1

	for k,v in sorted(d.items(), key=lambda x: (x[0])):
		print('%s %.04lf' % (k, (v/n_trees)*100))

	second = True

