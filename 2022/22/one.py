import re
d, dx, dy = 0, [0, 1, 0, -1], [1, 0, -1, 0]
grid = [line.rstrip() for line in open('input') if line.rstrip()]
cmd = grid.pop()
N = len(grid)
M = max(len(row) for row in grid)
for i, row in enumerate(grid):
    while len(row) < M:
        row += ' '
    grid[i] = row
x, y = 0, 0
while grid[x][y] == ' ':
    y += 1
while cmd:
    if cmd[0] in 'LR':
        d = (d + 1) % 4 if cmd[0] == 'R' else (d + 3) % 4
        cmd = cmd[1:]
    else:
        n = 0
        while cmd and cmd[0].isdigit():
            n = n * 10 + int(cmd[0])
            cmd = cmd[1:]
        for _ in range(n):
            xx = (x + dx[d]) % N
            yy = (y + dy[d]) % M
            if grid[xx][yy] == '#':
                break
            while grid[xx][yy] == ' ':
                xx = (xx + dx[d]) % N
                yy = (yy + dy[d]) % M
            if grid[xx][yy] == '#':
                break
            x, y = xx, yy
print((x + 1) * 1000 + (y + 1) * 4 + d)
