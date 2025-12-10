from itertools import combinations
import sys

tiles = [
    tuple(int(x) for x in line.split(','))
    for line in sys.stdin
]

xs = sorted(set(x for x, _ in tiles))
ys = sorted(set(y for _, y in tiles))
xi = {x: i for i, x in enumerate(xs)}
yi = {y: i for i, y in enumerate(ys)}

edges = set()
for i in range(len(tiles)):
    x1, y1 = tiles[i]
    x2, y2 = tiles[(i + 1) % len(tiles)]
    if x1 == x2:
        for y in range(min(y1, y2), max(y1, y2) + 1):
            edges.add((x1, y))
    else:
        for x in range(min(x1, x2), max(x1, x2) + 1):
            edges.add((x, y1))


def is_inside(px, py):
    if (px, py) in edges:
        return True
    cnt = 0
    for i in range(len(tiles)):
        x1, y1 = tiles[i]
        x2, y2 = tiles[(i + 1) % len(tiles)]
        if x1 == x2:
            if x1 < px and min(y1, y2) < py <= max(y1, y2):
                cnt += 1
    return cnt % 2 == 1


c = set()
for x in xs:
    for y in ys:
        if is_inside(x, y):
            c.add((xi[x], yi[y]))

print(max(
    (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1)
    for (x1, y1), (x2, y2) in combinations(tiles, 2)
    if all(
        (i, j) in c
        for i in range(xi[min(x1, x2)], xi[max(x1, x2)] + 1)
        for j in range(yi[min(y1, y2)], yi[max(y1, y2)] + 1)
    )
))

