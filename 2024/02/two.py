import sys
from itertools import pairwise


def check(a, rec=False):
    if (all(1 <= abs(x - y) <= 3 for x, y in pairwise(a))
        and (
            all(x < y for x, y in pairwise(a))
            or all(x > y for x, y in pairwise(a))
        )
    ):
        return True
    good = False
    if rec:
        for i in range(len(a)):
            good = good or check(a[:i] + a[i + 1:])
    return good

total = 0
for line in sys.stdin:
    line = line.strip()
    a = [int(x) for x in line.split()]
    if check(a, True):
        total += 1

print(total)
