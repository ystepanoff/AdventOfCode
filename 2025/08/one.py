import math
import sys
from itertools import combinations


class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n + 1)]
        self.sz = [1] * (n + 1)

    def find_set(self, x):
        if self.p[x] == x:
            return x
        self.p[x] = self.find_set(self.p[x])
        return self.p[x]

    def union(self, x, y):
        x = self.find_set(x)
        y = self.find_set(y)
        if x == y:
            return
        if self.sz[x] < self.sz[y]:
            x, y = y, x
        self.p[y] = x
        self.sz[x] += self.sz[y]


coords = [tuple(map(int, line.split(','))) for line in sys.stdin]

n = len(coords) 
e = [
    ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2, i + 1, j + 1)
    for (i, (x1, y1, z1)), (j, (x2, y2, z2)) in combinations(enumerate(coords), 2)
]
e.sort()

dsu = DSU(n)
for _, i, j in e[:1000]:
    dsu.union(i, j)

roots = {dsu.find_set(i) for i in range(1, n + 1)}
sizes = sorted((dsu.sz[r] for r in roots), reverse=True)
print(math.prod(sizes[:3]))
