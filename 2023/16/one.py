import sys
sys.setrecursionlimit(50000)

GRID = []
ENERGISED = set()
VISITED = set()
DX = [0, 1, 0, -1]
DY = [1, 0, -1, 0]
DIRS = {
    '.': {0: 0, 1: 1, 2: 2, 3: 3},
    '/': {0: 3, 1: 2, 2: 1, 3: 0},
    '\\': {0: 1, 1: 0, 2: 3, 3: 2},
    '|': {0: (1, 3), 1: 1, 2: (1, 3), 3: 3},
    '-': {0: 0, 1: (0, 2), 2: 2, 3: (0, 2)},
}


def walk(x, y, d, steps):
    global GRID, ENERGISED, VISITED, DX, DY, DIRS
    
    n, m = len(GRID), len(GRID[0])
    if steps > n * m or not (0 <= x < n and 0 <= y < m) or (x, y, d) in VISITED:
        return
    ENERGISED.add((x, y))
    VISITED.add((x, y, d))
    new_d = DIRS[GRID[x][y]][d]
    if isinstance(new_d, tuple):
        d1, d2 = new_d
        walk(x + DX[d1], y + DY[d1], d1, steps + 1)
        walk(x + DX[d2], y + DY[d2], d2, steps + 1)
    else:
        walk(x + DX[new_d], y + DY[new_d], new_d, steps + 1)


for line in sys.stdin:
    GRID.append(line.rstrip())

walk(0, 0, 0, 0)
print(len(ENERGISED))
