grid = []
for line in open('input'):
    grid.append(line.strip())
n, m = len(grid), len(grid[0])
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'S':
            xs, ys = i, j
            grid[i] = grid[i].replace('S', 'a')
        elif grid[i][j] == 'E':
            xe, ye = i, j
            grid[i] = grid[i].replace('E', 'z')
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
q = [(xs, ys)]
d = [[0 for _ in range(m)] for _ in range(n)]
u = [[False for _ in range(m)] for _ in range(n)]
u[xs][ys] = True
for x, y in q:
    for i in range(4):
        xx, yy = x + dx[i], y + dy[i]
        if xx >= 0 and yy >= 0 and xx < n and yy < m and \
           ord(grid[xx][yy]) <= ord(grid[x][y]) + 1 and \
           u[xx][yy] == False:
            q.append((xx, yy))
            d[xx][yy] = d[x][y] + 1
            u[xx][yy] = True
print(d[xe][ye])
