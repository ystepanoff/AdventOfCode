import sys


G = {}


def topsort(a):
    visited = set()
    ts = []

    def dfs(u):
        visited.add(u)
        for v in G[u]:
            if v in a and v not in visited:
                dfs(v)
        if u in a:
            ts.append(u)

    for u in a:
        if u not in visited:
            dfs(u)
    return ts[::-1]



edges = []
total = 0
state = 1
for line in sys.stdin:
    line = str(line).rstrip()
    if not line:
        state = 0
        continue
    if state:
        u, v = line.split('|')
        edges.append((u, v))
        if u not in G:
            G[u] = []
        if v not in G:
            G[v] = []
        G[u].append(v)
    else:
        a = line.split(',')
        if any(a.index(u) > a.index(v) for u, v in edges if u in a and v in a):
            a = topsort(a)
            total += int(a[len(a) // 2])

print(total)
