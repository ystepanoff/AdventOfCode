import sys

G = {i + j * 1j for i in range(71) for j in range(71)}
inp = [int(j) + int(i) * 1j for i, j in [line.split(',') for line in sys.stdin]]


def bfs():
    q = [0]
    dist = {0: 0}
    while q:
        u = q.pop(0)
        for i in range(4):
            v = u + (-1j) ** i
            if v in G and v not in dist:
                dist[v] = dist[u] + 1
                q.append(v)
    return 70 + 70j in dist


grid = G.copy()
l, r = -1, len(inp)
while r - l > 1:
    m = (l + r) >> 1
    G = grid - set(inp[:m + 1])
    l, r = (m, r) if bfs() else (l, m)
print(f"{int(inp[r].imag)},{int(inp[r].real)}")
