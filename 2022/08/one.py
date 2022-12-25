grid = [[int(h) for h in line.strip()] for line in open('input')]
n, m = len(grid), len(grid[0])
total = 2 * (n + m) - 4
for i in range(1, n - 1):
    for j in range(1, m - 1):
        l = all(grid[i][y] < grid[i][j] for y in range(j))
        r = all(grid[i][y] < grid[i][j] for y in range(j + 1, m))
        u = all(grid[x][j] < grid[i][j] for x in range(i))
        d = all(grid[x][j] < grid[i][j] for x in range(i + 1, n))
        if any([l, r, u, d]):
            total += 1
print(total)
