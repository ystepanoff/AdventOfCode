import sys
from collections import defaultdict


G = defaultdict(set)
for line in sys.stdin:
    u, v = line.rstrip().split('-')
    G[u].add(v)
    G[v].add(u)

print(len({
    tuple(sorted((u, v, w)))
    for u in G
    for v in G[u]
    for w in G[u].intersection(G[v])
    if len({u, v, w}) == 3 and any(x[0] == 't' for x in (u, v, w))
}))
