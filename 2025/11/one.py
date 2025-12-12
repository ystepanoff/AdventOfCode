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

dfs('you')
ways = {u: 0 for u in ts} 
ways['you'] = 1
for u in ts[::-1]:
    for v in G.get(u, []):
        ways[v] += ways[u]
print(ways['out'])
