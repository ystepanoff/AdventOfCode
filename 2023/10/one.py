from collections import defaultdict
import sys

LEFT = (0, -1)
RIGHT = (0, 1)
UP = (-1, 0)
DOWN = (1, 0)

MATCH = {
    LEFT: "-FL",
    RIGHT: "-J7",
    UP: "|7F",
    DOWN: "|JL",
}

def check(ch1, ch2, d):
    dirs = None
    if ch2 == 'S':
        return True
    match ch1:
        case '|':
            dirs = [UP, DOWN]
        case '-':
            dirs = [LEFT, RIGHT]
        case 'L':
            dirs = [UP, RIGHT]
        case 'J':
            dirs = [UP, LEFT]
        case '7':
            dirs = [DOWN, LEFT]
        case 'F':
            dirs = [DOWN, RIGHT]
        case 'S':
            dirs = [UP, DOWN, LEFT, RIGHT]
    return d in dirs and ch2 in MATCH[d]

grid = []
for line in sys.stdin:
    grid.append(list(line.rstrip()))

n, m = len(grid), len(grid[0])
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'S':
            xs, ys = i, j

path = [(xs, ys)]
while True:
    if len(path) > 1 and path[-1] == (xs, ys):
        break
    x, y = path[-1]
    for dx, dy in [LEFT, RIGHT, UP, DOWN]:
        xx, yy = x + dx, y + dy
        if 0 <= xx < n and 0 <= yy < m:
            if check(grid[x][y], grid[xx][yy], (dx, dy)) and not (xx, yy) in path:
                path.append((xx, yy))
                break
    else:
        break

print(len(path) >> 1)
