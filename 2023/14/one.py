import sys

grid = []
for line in sys.stdin:
    line = line.rstrip()
    grid.append(list(line))

n, m = len(grid), len(grid[0])
total = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'O':
            load = n - i
            k = i - 1
            while k >= 0 and grid[k][j] == '.':
                grid[k + 1][j] = '.'
                grid[k][j] = 'O'
                k -= 1
                load += 1
            total += load
print(total)
