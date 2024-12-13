import re
import sys


def solve(ax, ay, bx, by, x, y):
    d = ax * by - ay * bx
    dx = x * by - y * bx
    dy = ax * y - ay * x
    if dx % d == 0 and dy % d == 0:
        return (dx // d) * 3 + (dy // d)
    return 0


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
        total += solve(ax, ay, bx, by, x + 10 ** 13, y + 10 ** 13)
print(total)
