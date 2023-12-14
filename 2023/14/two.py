import sys


def tilt(grid, s):
    n, m = len(grid), len(grid[0])
    if s == 'N':
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'O':
                    x = i - 1
                    while x >= 0 and grid[x][j] == '.':
                        grid[x + 1][j] = '.'
                        grid[x][j] = 'O'
                        x -= 1
    elif s == 'S':
        for i in range(n - 1, -1, -1):
            for j in range(m):
                if grid[i][j] == 'O':
                    x = i + 1
                    while x < n and grid[x][j] == '.':
                        grid[x - 1][j] = '.'
                        grid[x][j] = 'O'
                        x += 1
    elif s == 'W':
        for j in range(m):
            for i in range(n):
                if grid[i][j] == 'O':
                    y = j - 1
                    while y >= 0 and grid[i][y] == '.':
                        grid[i][y + 1] = '.'
                        grid[i][y] = 'O'
                        y -= 1
    elif s == 'E':
        for j in range(m - 1, -1, -1):
            for i in range(n):
                if grid[i][j] == 'O':
                    y = j + 1
                    while y < m and grid[i][y] == '.':
                        grid[i][y - 1] = '.'
                        grid[i][y] = 'O'
                        y += 1
    return grid


grid = []
for line in sys.stdin:
    line = line.rstrip()
    grid.append(list(line))

n, m = len(grid), len(grid[0])

N = 1000000000

seen = {}
cache = {}
pre_period = 0
period = 0
times = 0
for cycle in range(N):
    total = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'O':
                total += n - i
    cache[cycle] = total
    for s in "NWSE":
        grid = tilt(grid, s)
    key = tuple(tuple(row) for row in grid)
    if key in seen:
        if pre_period == 0:
            pre_period = cycle + 1
        elif period == 0:
            period = cycle - seen[key]
        times += 1
        if pre_period != 0 and period != 0 and times == pre_period + ((N - pre_period) % period):
            break
    else:
        seen[key] = cycle

print(cache[pre_period + (N - pre_period) % period])
