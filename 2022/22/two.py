import re
d, dx, dy = 1, [-1, 0, 1, 0], [0, 1, 0, -1]
grid = [line.rstrip() for line in open('input') if line.rstrip()]
cmd = grid.pop()
SIDE = min(len(row) - row.count(' ') for row in grid)
N = len(grid)
M = max(len(row) for row in grid)
for i, row in enumerate(grid):
    while len(row) < M:
        row += ' '
    grid[i] = row


# thus, this solution will only work with the cube layout given in the input
REGIONS = [
    (0, 1),
    (0, 2),
    (1, 1),
    (2, 1),
    (2, 0),
    (3, 0),
]


def region_global(x, y, r):
    xx, yy = REGIONS[r - 1]
    return xx * SIDE + x, yy * SIDE + y


def get_region(x, y):
    for i, (xx, yy) in enumerate(REGIONS):
        if xx * SIDE <= x < (xx + 1) * SIDE and yy * SIDE <= y < (yy + 1) * SIDE:
            return i + 1, x - xx * SIDE, y - yy * SIDE
    assert False, (x, y)

    
def new_coords(x, y, d, nd):
    if d == 0:
        t = y
    if d == 1:
        t = x
    if d == 2:
        t = SIDE - 1 - y
    if d==3:
        t = SIDE - 1 - x

    if nd == 0:
        return SIDE - 1, t
    if nd == 1:
        return t, 0
    if nd == 2:
        return 0, SIDE - 1 - t
    if nd == 3:
        return SIDE - 1 - t, SIDE - 1

def get_destination(x, y, d):
    region, xx, yy = get_region(x, y)
    new_region, nd = {
        (4, 0): (3, 0),
        (4, 1): (2, 3),
        (4, 2): (6, 3),
        (4, 3): (5, 3),
        (1, 0): (6, 1),
        (1, 1): (2, 1),
        (1, 2): (3, 2),
        (1, 3): (5, 1),
        (3, 0): (1, 0),
        (3, 1): (2, 0),
        (3, 2): (4, 2),
        (3, 3): (5, 2),
        (6, 0): (5, 0),
        (6, 1): (4, 0),
        (6, 2): (2, 2),
        (6, 3): (1, 2),
        (2, 0): (6, 0),
        (2, 1): (4, 3),
        (2, 2): (3, 3),
        (2, 3): (1, 3),
        (5, 0): (3, 1),
        (5, 1): (4, 1),
        (5, 2): (6, 2),
        (5, 3): (1, 1),
    }[region, d]

    xx, yy = new_coords(xx, yy, d, nd)
    xx, yy = region_global(xx, yy, new_region)
    return xx, yy, nd
    
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
            if grid[xx][yy] == ' ':
                nx, ny, nd = get_destination(x, y, d)
                if grid[nx][ny] == '#':
                    break
                x, y, d = nx, ny, nd
                continue
            elif grid[xx][yy] == '#':
                break
            else:
                x, y = xx, yy
print((x + 1) * 1000 + (y + 1) * 4 + (d + 3) % 4)
