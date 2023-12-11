import sys


def double_rows(a):
    b = []
    for row in a:
        b.append(row)
        if all(c == '.' for c in row):
            b.append(row)
    return b


def transpose(a):
    n, m = len(a), len(a[0])
    b = [[a[i][j] for i in range(n)] for j in range(m)]
    return b


a = []
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        break
    a.append(list(line))

a = double_rows(a)
a = transpose(a)
a = double_rows(a)
a = transpose(a)


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
        total += abs(xi - xj) + abs(yi - yj)
print(total)
