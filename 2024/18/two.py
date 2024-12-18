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


for v in inp:
	G.discard(v)
	if not bfs():
		print(f"{int(v.imag)},{int(v.real)}")
		break