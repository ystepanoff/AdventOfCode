import sys
from collections import defaultdict


OPS = {
    'AND': lambda x, y: x & y,
    'OR': lambda x, y: x | y,
    'XOR': lambda x, y: x ^ y,
}


G, w, q = defaultdict(list), {}, []
for line in sys.stdin:
    parts = line.rstrip().split()
    if len(parts) == 2:
        w[parts[0][:-1]] = int(parts[1])
        q.append(parts[0][:-1])
    elif len(parts) == 5:
        G[parts[0]].append((parts[2], parts[4], OPS[parts[1]]))
        G[parts[2]].append((parts[0], parts[4], OPS[parts[1]]))

for a in q:
    for b, c, op in G[a]:
        if b in w and c not in w:
            w[c] = op(w[a], w[b])
            q.append(c)

result = 0
for v in G:
    if v[0] == 'z':
        result |= w[v] << int(v[1:])
print(result)
