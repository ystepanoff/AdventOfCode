import sys


WORD = "XMAS"


def check(grid, word, x, y, dx, dy):
    for i, ch in enumerate(word):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] != ch:
            return False
        x += dx
        y += dy
    return True


grid = []
for line in sys.stdin:
    line = line.strip()
    if line:
        grid.append(line)


total = 0
for x in range(len(grid)):
    for y in range(len(grid[0])):
        for dx, dy in [
            (-1, 0), (1, 0), (0, -1), (0, 1),
            (-1, 1), (1, -1), (1, 1), (-1, -1),
        ]:
            if check(grid, WORD, x, y, dx, dy):
                total += 1

print(total)
