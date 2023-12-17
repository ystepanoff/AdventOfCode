from heapq import heappop, heappush
import sys

G = {
    i + j * 1j: int(h)
    for i, line in enumerate(sys.stdin)
    for j, h in enumerate(line.rstrip())
}

q = [(0, 0, 0, d) for d in [1, 1j]]
x = 0
seen = set()

while q:
    v, _, p, d = heappop(q)
    if p == [*G][-1]:
        print(v)
        break
    if (p, d) in seen:
        continue
    seen.add((p, d))

    for new_d in -1j / d, 1j / d:
        for s in range(4, 11):
            new_p = p + new_d * s
            if new_p in G:
                w = sum(G[p + new_d * j] for j in range(1, s + 1))
                heappush(q, (v + w, (x := x + 1), new_p, new_d))
