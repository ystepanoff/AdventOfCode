from collections import defaultdict
import sys


def move(bricks, skip_idx=None):
    tops = defaultdict(int)
    moves = 0
    new_bricks = bricks.copy()
    for i, (x1, y1, z1, x2, y2, z2) in enumerate(bricks):
        if i == skip_idx:
            continue
        level = [
            (x, y)
            for x in range(x1, x2 + 1)
            for y in range(y1, y2 + 1)
        ]
        top = max(tops[lv] for lv in level) + 1
        for lv in level:
            tops[lv] = top + z2 - z1
        new_bricks[i] = (x1, y1, top, x2, y2, top + z2 - z1)
        moves += top < z1
    return moves, new_bricks


bricks = []
max_x, max_y, max_z = 0, 0, 0
for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    xyz, lwh = line.split('~')
    x1, y1, z1 = map(int, xyz.split(','))
    x2, y2, z2 = map(int, lwh.split(','))
    assert (x2, y2) == (x1, y1) or (x2, z2) == (x1, z1) or (y2, z2) == (y1, z1)
    bricks.append((x1, y1, z1, x2, y2, z2))

bricks = sorted(bricks, key=lambda b: b[2])
_, bricks = move(bricks.copy())

total = 0
for i in range(len(bricks)):
    moves, _ = move(bricks.copy(), skip_idx=i)
    total += moves
print(total)
