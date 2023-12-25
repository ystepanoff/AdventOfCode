import sys

ADD = 1000000

a = []
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        break
    a.append(list(line))

n, m = len(a), len(a[0])
gal = {}
c = 0
for x in range(n):
    for y in range(m):
        if a[x][y] == '#':
            gal[c] = (x, y)
            c += 1

total = 0
for i in range(c):
    for j in range(i + 1, c):
        xi, yi = gal[i]
        xj, yj = gal[j]

        empty_rows = 0
        empty_cols = 0
        
        for x in range(min(xi, xj), max(xi, xj)):
            if all(a[x][y] == '.' for y in range(m)):
                empty_cols += 1    
        for y in range(min(yi, yj), max(yi, yj)):
            if all(a[x][y] == '.' for x in range(n)):
                empty_rows += 1
                
        total += abs(xi - xj) + abs(yi - yj) + (empty_rows + empty_cols) * (ADD - 1)
print(total)
