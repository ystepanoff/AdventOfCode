import math
import sys

turns = None
nodes = {}

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    if '=' not in line:
        turns = line
    else:
        node, children = line.split(' = ')
        nodes[node] = children[1:-1].split(', ')

curr = []
for node in nodes:
    if node[-1] == 'A':
        curr.append(node)

total = 1
for node in curr:
    steps = 0
    while node[-1] != 'Z':
        if turns[steps % len(turns)] == 'L':
            node = nodes[node][0]
        else:
            node = nodes[node][1]
        steps += 1
    total = total * steps // math.gcd(total, steps)

print(total)

