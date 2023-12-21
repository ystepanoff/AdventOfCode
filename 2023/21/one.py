import sys

G = {}
steps = 64 + 1

for i, line in enumerate(sys.stdin):
    line = line.strip()
    if not line:
        continue
    for j, c in enumerate(line):
        G[i + 1j * j] = c

grid = G.copy()
while (steps := steps - 1):
    new_grid = G.copy()
    for pos in grid:
        if grid[pos] not in ['S', 'O']:
            continue
        for dir in [-1, 1, -1j, 1j]:
            new_pos = pos + dir
            if new_pos in grid and grid[new_pos] != '#':
                new_grid[new_pos] = 'O'
        new_grid[pos] = '.'
    grid = new_grid.copy()
    print(sum(1 for pos in grid if grid[pos] == 'O'))
