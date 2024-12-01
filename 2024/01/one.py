import sys

a, b = [], []
for line in sys.stdin:
	x, y = map(int, line.split())
	a.append(x)
	b.append(y)

a.sort()
b.sort()

print(a, b)

total = 0
for x, y in zip(a, b):
	print(x, y)
	total += abs(x - y)

print(total)
