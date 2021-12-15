import sys

grid = [[0 for j in range(1000)] for i in range(1000)]

for line in sys.stdin:
    line = line.strip()
    f, t = line.split(" -> ")
    fx, fy = map(int, f.split(','))
    tx, ty = map(int, t.split(','))
    if fx == tx:
        for j in range(min(fy, ty), max(fy, ty) + 1):
            grid[j][fx] += 1
    elif fy == ty:
        for i in range(min(fx, tx), max(fx, tx) + 1):
            grid[fy][i] += 1

c = 0
for i in range(1000):
    for j in range(1000):
        if grid[i][j] > 1:
            c += 1

print(c)
