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

curr = 'AAA'
steps = 0
while curr != 'ZZZ':
    if turns[steps % len(turns)] == 'L':
        curr = nodes[curr][0]
    else:
        curr = nodes[curr][1]
    steps += 1

print(steps)
