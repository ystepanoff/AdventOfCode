import sys

edges = []
total = 0
state = 1
for line in sys.stdin:
	line = str(line).rstrip()
	if not line:
		state = 0
		continue
	if state:
		edges.append(line.split('|'))
	else:
		a = line.split(',')
		if all(a.index(u) < a.index(v) for u, v in edges if u in a and v in a):
			total += int(a[len(a) // 2])

print(total)
