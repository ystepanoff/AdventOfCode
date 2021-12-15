import sys
from collections import defaultdict

cnt = defaultdict(int)

for line in sys.stdin:
    line = line.strip()
    f, t = line.split(" -> ")
    fx, fy = map(int, f.split(','))
    tx, ty = map(int, t.split(','))
    dx, dy = tx - fx, ty - fy
    for i in range(max(abs(dx), abs(dy)) + 1):
        x = fx + (1 if dx > 0 else (-1 if dx < 0 else 0)) * i
        y = fy + (1 if dy > 0 else (-1 if dy < 0 else 0)) * i
        cnt[(x, y)] += 1

print(len([p for p, c in cnt.items() if c > 1]))
