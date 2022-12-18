import sys
sys.setrecursionlimit(1500)

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

EXTERIOR = [[[False for _ in range(100)] for _ in range(100)] for _ in range(100)]
q = [(0, 0, 0)]
EXTERIOR[0][0][0] = True
for x, y, z in q:
    for d in range(6):
        xx, yy, zz = x + DX[d], y + DY[d], z + DZ[d]
        if min(xx, yy, zz) >= 0 and max(xx, yy, zz) < 100 and \
           GRID[xx][yy][zz] == 0 and EXTERIOR[xx][yy][zz] == False:
            q.append((xx, yy, zz))
            EXTERIOR[xx][yy][zz] = True

def dfs(x, y, z):
    global GRID, VISITED, EXTERIOR, DX, DY, DZ, TOTAL
    
    VISITED[x][y][z] = True
    ch = 0
    for d in range(6):
        xx, yy, zz = x + DX[d], y + DY[d], z + DZ[d]
        if GRID[xx][yy][zz] == 1:
            ch += 1
            if VISITED[xx][yy][zz] is False:
                dfs(xx, yy, zz)
        elif not EXTERIOR[xx][yy][zz]:
            ch += 1
    TOTAL += 6 - ch


for x in range(100):
    for y in range(100):
        for z in range(100):
            if GRID[x][y][z] == 1 and VISITED[x][y][z] is False:
                dfs(x, y, z)

print(TOTAL)
