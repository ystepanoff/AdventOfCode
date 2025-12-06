from functools import reduce
import operator
import sys

ops = {
    '*': operator.mul,
    '+': operator.add,
}

p, total = [], 0
for line in sys.stdin:
    p.append(line.rstrip().split())
for i in range(len(p[0])):
    total += reduce(
        ops[p[-1][i]], 
        [int(c[i]) for c in p[:-1]]
    )
print(total)
