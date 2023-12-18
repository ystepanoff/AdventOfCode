from collections import defaultdict
import sys

dirs = {
    'U': (-1, 0),
    'D': (1, 0),
    'R': (0, 1),
    'L': (0, -1),
}

grid = defaultdict(bool)
curr = (0, 0)
grid[curr] = True
path = [curr]
last_d = None

for line in sys.stdin:
    line = line.rstrip()
    d, s, _ = line.split()
    for _ in range(int(s)):
        curr = tuple(map(sum, zip(curr, dirs[d])))
        grid[curr] = True
    if d != last_d and curr not in path:
        path.append(curr)
    last_d = d

length = 1
sum1, sum2 = 0, 0
for i in range(1, len(path)):
    x1, y1 = path[i - 1]
    x2, y2 = path[i]
    length += abs(x1 - x2) + abs(y1 - y2)
    sum1 += x1 * y2
    sum2 += x2 * y1
print(int(length / 2 + 2 + abs(sum1 - sum2) / 2))
