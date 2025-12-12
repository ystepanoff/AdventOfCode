import sys
from itertools import combinations as c

print(sum(max(int(a+b) for a, b in c(line.strip(), 2)) for line in sys.stdin))
