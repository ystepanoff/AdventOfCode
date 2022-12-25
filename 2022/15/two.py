import re

reports, sensors, beacons = [], set(), set()
for line in open('input'):
    xs, ys, xb, yb = [int(x) for x in re.findall(r'[-+]?\d+', line)]
    sensors.add((xs, ys))
    beacons.add((xb, yb))
    reports.append((xs, ys, xb, yb))


def union_length(segments):
    n = len(segments)
    points = [None] * (2 * n)
    for i in range(n):
        points[2 * i] = (segments[i][0], False)
        points[2 * i + 1] = (segments[i][1], True)
    points = sorted(points, key = lambda t: t[0])
    result, count = 0, 0
    for i in range(2 * n):
        if i > 0 and (points[i][0] > points[i - 1][0]) and count > 0:
            result += points[i][0] - points[i - 1][0]
        if points[i][1]:
            count -= 1
        else:
            count += 1
    return result

    
def count_covering(y):
    segments = []
    for xs, ys, xb, yb in reports:
        dmax = abs(xs - xb) + abs(ys - yb)
        if abs(y - ys) <= dmax:
            left = max(xs - dmax + abs(y - ys), 0)
            right = min(xs + dmax - abs(y - ys), 4000000)
            segments.append((left, right))
    if union_length(segments) < 4000000:
        for x in range(0, 4000001):
            covered = False
            for left, right in segments:
                if left <= x <= right:
                    covered = True
                    break
            if not covered:
                print(x * 4000000 + y)
        return True
    else:
        return False

for y in range(4000000, 0, -1):
    if count_covering(y):
        break
