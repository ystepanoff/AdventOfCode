from decimal import *


N = 2000000


def gen_points():
    points = []
    s = 290797
    for i in range(2 * N - 1):
        t = (s * s) % 50515093
        if i % 2 == 0:
            points.append((Decimal(s), Decimal(t)))
        s = t
    return points


def solve_naive(points):
    best = Decimal('Infinity')
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            x = points[i][0] - points[j][0]
            y = points[i][1] - points[j][1]
            d2 = x * x + y * y
            best = min(best, d2.sqrt())
    return best, sorted(points, key=lambda t: t[1])


def merge(a, b):
    c = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i][1] <= b[j][1]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    while i < len(a):
        c.append(a[i])
        i += 1
    while j < len(b):
        c.append(b[j])
        j += 1
    return c


def closest_pair_distance(points):
    if len(points) <= 5:
        return solve_naive(points)
    mid = len(points) // 2
    left, right = points[:mid], points[mid:]
    l = (left[-1][0] + right[0][0]) / 2
    d1, left = closest_pair_distance(left)
    d2, right = closest_pair_distance(right)
    d, merged = min(d1, d2), merge(left, right)
    remaining = [(x, y) for x, y in merged \
                 if abs(l - x) <= d]
    for i, (x, y) in enumerate(remaining):
        for j in range(i - 3, i + 4):
            if j >= 0 and j < len(remaining) and j != i:
                d2 = (x - remaining[j][0]) ** 2 + (y - remaining[j][1]) ** 2
                d = min(d, d2.sqrt())
    return d, merged


def solve(points):
    points = sorted(points, key=lambda t: t[0])
    return closest_pair_distance(points)


points = gen_points()
#print('{:.9f}'.format(solve_naive(points)))
d, _ = solve(points)
print('{:.9f}'.format(d))
