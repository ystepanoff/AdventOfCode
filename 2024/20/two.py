import sys
from itertools import combinations


G = {
    i + j * 1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
    if ch != "#"
}
start, = (x for x, ch in G.items() if ch == "S")
q, dist = [start], {start: 0}
for u in q:
    for i in range(4):
        v = u + (-1j) ** i
        if v in G and v not in dist:
            q.append(v)
            dist[v] = dist[u] + 1
total = 0
for (x, dx), (y, dy) in combinations(dist.items(), 2):
    s = abs((x - y).real) + abs((x - y).imag)
    if s + 100 <= dy - dx and s <= 20:
        total += 1
print(total)
