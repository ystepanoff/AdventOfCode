import re
reports, sensors, beacons = [], set(), set()
for line in open('input'):
    xs, ys, xb, yb = [int(x) for x in re.findall(r'[-+]?\d+', line)]
    sensors.add((xs, ys))
    beacons.add((xb, yb))
    reports.append((xs, ys, xb, yb))
y = 2000000
total = 0
for x in range(-10000000, 10000001):
    if (x, y) in beacons.union(sensors):
        continue
    covered = False
    for xs, ys, xb, yb in reports:
        d = abs(xs - x) + abs(ys - y)
        dmax = abs(xs - xb) + abs(ys - yb)
        if d <= dmax:
            covered = True
            break
    if covered:
        total += 1
print(total)
