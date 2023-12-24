import sys

lines = []

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    pos, vel = line.split(' @ ')
    pos = [int(x) for x in pos.split(', ')]
    vel = [int(x) for x in vel.split(', ')]
    lines.append((pos, vel))

min_x, max_x = 200000000000000, 400000000000000
min_y, max_y = min_x, max_x

total = 0
for i, ((x1, y1, _), (a1, b1, _)) in enumerate(lines):
    for j, ((x2, y2, _), (a2, b2, _)) in enumerate(lines[i+1:]):
        d = a2 * b1 - a1 * b2
        if d != 0:
            d1 = a2 * (y2 - y1) - b2 * (x2 - x1)
            d2 = a1 * (y2 - y1) - b1 * (x2 - x1)
            t1, t2 = d1 / d, d2 / d
            x, y = x1 + t1 * a1, y1 + t1 * b1
            if t1 >= 0 and t2 >= 0 and min_x <= x <= max_x and min_y <= y <= max_y:
                total += 1
print(total)
