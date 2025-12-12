import sys

G = {}
for line in sys.stdin:
    u, to = line.rstrip().split(": ")
    G[u] = to.split()

vis, ts = set(), []
def dfs(u):
    vis.add(u)
    for v in G.get(u, []):
        if v not in vis:
            dfs(v)
    ts.append(u)

dfs('svr')
ways = {u: [0, 0, 0, 0] for u in ts} 
ways['svr'] = [1, 0, 0, 0]
for u in ts[::-1]:
    for v in G.get(u, []):
        for i in range(4):
            j = i | (2 if v == 'dac' else 0) | (1 if v == 'fft' else 0)
            ways[v][j] += ways[u][i]
print(ways['out'][3])
