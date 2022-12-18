import sys
sys.setrecursionlimit(10000)

GRID = [[[0 for _ in range(100)] for _ in range(100)] for _ in range(100)]
for line in open('input'):
    line = line.rstrip()
    x, y, z = map(int, line.split(','))
    GRID[x][y][z] = 1
VISITED = [[[False for _ in range(100)] for _ in range(100)] for _ in range(100)]
DX = [0, 0, 0, 0, 1, -1]
DY = [0, 0, 1, -1, 0, 0]
DZ = [1, -1, 0, 0, 0, 0]
TOTAL = 0

def dfs(x, y, z):
    global GRID, VISITED, DX, DY, DZ, TOTAL
    
    VISITED[x][y][z] = True
    ch = 0
    for d in range(6):
        xx, yy, zz = x + DX[d], y + DY[d], z + DZ[d]
        if GRID[xx][yy][zz] == 1:
            ch += 1
            if VISITED[xx][yy][zz] is not True:
                dfs(xx, yy, zz)
    TOTAL += 6 - ch


for x in range(100):
    for y in range(100):
        for z in range(100):
            if GRID[x][y][z] == 1 and VISITED[x][y][z] is not True:
                dfs(x, y, z)
print(TOTAL)
