import sys

def check(grid, i, j):
    n, m = len(grid), len(grid[0])
    for x in range(i - 1, i + 2):
        for y in range(j - 1, j + 2):
            if (x, y) == (i, j):
                continue
            if x >= 0 and y >= 0 and x < n and y < m and grid[x][y] != '.' and not grid[x][y].isdigit():
                return True
    return False

grid = []
for line in sys.stdin:
    grid.append(line.rstrip())
n, m = len(grid), len(grid[0])
total = 0
for i in range(n):
    j = 0
    while j < m:
        if grid[i][j].isdigit():
            k = j
            ok = False
            while k < m and grid[i][k].isdigit():
                ok = ok or check(grid, i, k)
                k += 1
            if ok:
                total += int(grid[i][j:k])
            j = k
        j += 1
print(total)

