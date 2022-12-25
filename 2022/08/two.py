def score(heights, ref):
    for i, h in enumerate(heights):
        if ref <= h:
            return i + 1
    return len(heights)

grid = [[int(h) for h in line.strip()] for line in open('input')]
n, m = len(grid), len(grid[0])
best = 0
for i in range(1, n - 1):
    for j in range(1, m - 1):
        l = score([grid[i][y] for y in range(j)][::-1], grid[i][j])
        r = score([grid[i][y] for y in range(j + 1, m)], grid[i][j])
        u = score([grid[x][j] for x in range(i)][::-1], grid[i][j])
        d = score([grid[x][j] for x in range(i + 1, n)], grid[i][j])
        best = max(best, l * r * u * d)
print(best)
