from itertools import combinations
import sys

tiles = [
    [int(x) for x in line.split(',')]
    for line in sys.stdin
]

print(max(
    abs(x1 - x2 + 1) * abs(y1 - y2 + 1)
    for (x1, y1), (x2, y2) in combinations(tiles, 2)
))
