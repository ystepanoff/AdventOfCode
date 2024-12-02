import sys
from itertools import pairwise

total = 0
for line in sys.stdin:
	line = line.strip()
	a = [int(x) for x in line.split()]
	if (all(1 <= abs(x - y) <= 3 for x, y in pairwise(a))
		and (
			all(x < y for x, y in pairwise(a))
			or all(x > y for x, y in pairwise(a))
		)
	):
		total += 1

print(total)
