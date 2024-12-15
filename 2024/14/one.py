import re
import sys


steps, w, h = 100, 101, 103
robots = [tuple(map(int, re.findall(r"-?\d+", line))) for line in sys.stdin]
robots = [((x + vx * steps) % w, (y + vy * steps) % h, vx, vy) for x, y, vx, vy in robots]
a, b, c, d = 0, 0, 0, 0
for x, y, _, _ in robots:
    if x > w // 2 and y > h // 2:
        a += 1
    elif x > w // 2 and y < h // 2:
        b += 1
    elif x < w // 2 and y > h // 2:
        c += 1
    elif x < w // 2 and y < h // 2:
        d += 1
print(a * b * c * d)
