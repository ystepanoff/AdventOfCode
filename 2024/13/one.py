import re
import sys


def solve(ax, ay, bx, by, x, y):
    best = -1
    for a in range(101):
        for b in range(101):
            cost = 3 * a + b
            X = ax * a + bx * b
            Y = ay * a + by * b
            if X == x and Y == y and (best == -1 or cost < best):
                best = cost
    return max(0, best)


total = 0
for line in sys.stdin:
    line = line.rstrip()
    match = re.search(r"Button A: X\+(\d+), Y\+(\d+)", line)
    if match:
        ax = int(match.group(1))
        ay = int(match.group(2))
    match = re.match(r"Button B: X\+(\d+), Y\+(\d+)", line)
    if match:
        bx = int(match.group(1))
        by = int(match.group(2))
    match = re.match(r"Prize: X=(\d+), Y=(\d+)", line)
    if match:
        x = int(match.group(1))
        y = int(match.group(2))
        total += solve(ax, ay, bx, by, x, y)
print(total)
