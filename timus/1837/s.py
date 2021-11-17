from collections import defaultdict
import sys

n = int(input())
g = defaultdict(set)

for line in sys.stdin:
    line = line.strip()
    p = line.split()
    for a in p:
        for b in p:
            if a != b:
                g[a].add(b)
                g[b].add(a)

start = 'Isenbaev'

if start in g.keys():
    q = [start]
    u = defaultdict(bool)
    d = defaultdict(int)
    u[start] = True
    for v in q:
        for c in g[v]:
            if not u[c]:
                q.append(c)
                u[c] = True
                d[c] = d[v] + 1

    for v in sorted(g.keys()):
        if u[v]:
            print(v, d[v])
        else:
            print(v, 'undefined')
else:
    for v in sorted(g.keys()):
        print(v, 'undefined')
