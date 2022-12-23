from collections import defaultdict
dirs, d = [
    ((-1, 0), [(-1, -1), (-1, 0), (-1, 1)]),
    ((1, 0), [(1, -1), (1, 0), (1, 1)]),
    ((0, -1), [(1, -1), (0, -1), (-1, -1)]),
    ((0, 1), [(-1, 1), (0, 1), (1, 1)]),
], 0
adj = [
    (-1, -1),
    (-1, 0),
    (-1, 1),
    (0, 1),
    (1, 1),
    (1, 0),
    (1, -1),
    (0, -1),
]
grid = [line.rstrip() for line in open('input')]
positions = []
for i, row in enumerate(grid):
    for j, c in enumerate(row):
        if c == '#':
            positions.append((i, j))
for r in range(10):
    moves = defaultdict(list)
    new_positions = []
    for x, y in positions:
        if all((x + dx, y + dy) not in positions for dx, dy in adj):
            new_positions.append((x, y))
            continue
        found = False
        for i in range(4):
            if all((x + dx, y + dy) not in positions for dx, dy in dirs[(d + i) % 4][1]):
                dx, dy = dirs[(d + i) % 4][0]
                moves[x + dx, y + dy].append((x, y))
                found = True
                break
        if not found:
            new_positions.append((x, y))
    d += 1
    for x, y in moves:
        if len(moves[x, y]) == 1:
            new_positions.append((x, y))
        else:
            new_positions.extend(moves[x, y])
    positions = new_positions.copy()
l = min(x for x, _ in positions)
r = max(x for x, _ in positions)
u = min(y for _, y in positions)
d = max(y for _, y in positions)
print((r - l + 1) * (d - u + 1) - len(positions))
