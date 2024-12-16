from collections import defaultdict
from heapq import heappush, heappop
import sys

G = {
    i + j*1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
    if ch != '#'
}

start = list(G.keys())[list(G.values()).index('S')]
end = list(G.keys())[list(G.values()).index('E')]
q = [(0, i := 0, 1j, start, [start])]
dist, tiles, best = defaultdict(lambda: 1e12), set(), 1e12
while q:
    dst, _, dv, v, curr = heappop(q)
    if dst <= dist[dv, v]:
        dist[dv, v] = dst
        if v == end and dst <= best:
            best = dst
            tiles.update(curr)
    else:
        continue
    for s, d in (1000 + 1, -1j), (1000 + 1, 1j), (1, 1):
        if v + dv * d in G:
            heappush(q, (dst + s, i := i+1, dv * d, v + dv * d, curr + [v]))
print(best)
print(1 + len(tiles))

