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
q = []
heappush(q, (0, int(start.real), int(start.imag), 0))
ds = {}
best = -1
while q:
    dst, x, y, d = heappop(q)
    d = dists[d]
    if x + y*1j == end and best == -1:
        best = dst
    if (x, y, d) not in ds:
        ds[x, y, d] = dst
    else:
        continue
    nxt = x + y*1j + d
    if G.get(nxt, '#') != '#':
        heappush(q, (dst + 1, int(nxt.real), int(nxt.imag), dists.index(d)))
    heappush(q, (dst + 1000, x, y, dists.index(d * -1j)))
    heappush(q, (dst + 1000, x, y, dists.index(d / -1j)))

q = []
for d in range(4):
    heappush(q, (0, int(end.real), int(end.imag), d))
de = {}
while q:
    dst, x, y, d = heappop(q)
    d = dists[d]
    if (x, y, d) not in de:
        de[x, y, d] = dst
    else:
        continue
    nxt = x + y*1j - d
    if G.get(nxt, '#') != '#':
        heappush(q, (dst + 1, int(nxt.real), int(nxt.imag), dists.index(d)))
    heappush(q, (dst + 1000, x, y, dists.index(d * -1j)))
    heappush(q, (dst + 1000, x, y, dists.index(d / -1j)))

tiles = set()
for cell in G:
    for d in range(4):
        x, y = int(cell.real), int(cell.imag)
        if (x, y, dists[d]) in ds and (x, y, dists[d]) in de and ds[x, y, dists[d]] + de[x, y, dists[d]] == best:
            tiles.add((x, y))
print(len(tiles))
