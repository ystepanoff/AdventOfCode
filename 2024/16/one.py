from heapq import heappush, heappop
import sys

G = {
    i + j*1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}

start = list(G.keys())[list(G.values()).index('S')]
end = list(G.keys())[list(G.values()).index('E')]

dists = [1j, 1, -1j, -1]
q, visited = [], set()
heappush(q, (0, int(start.real), int(start.imag), 0))
best = -1
while q:
    dst, x, y, d = heappop(q)
    d = dists[d]
    if x + y*1j == end and best == -1:
        best = dst
    if (x, y, d) in visited:
        continue
    visited.add((x, y, d))
    nxt = x + y*1j + d
    if G.get(nxt, '#') != '#':
        heappush(q, (dst + 1, int(nxt.real), int(nxt.imag), dists.index(d)))
    heappush(q, (dst + 1000, x, y, dists.index(d * -1j)))
    heappush(q, (dst + 1000, x, y, dists.index(d / -1j)))
print(best)
