import sys
from collections import defaultdict


def gen(n):
    m = ((n << 6) ^ n) & 0xffffff
    m = ((m >> 5) ^ m) & 0xffffff
    return ((m << 11) ^ m) & 0xffffff


total = defaultdict(int)
for line in sys.stdin:
    n = int(line)
    p = [n] + [n := gen(n) for _ in range(2000)]
    d = [m % 10 - n % 10 for m, n in zip(p[1:], p)]
    seen = set()
    for t, val in zip(zip(d, d[1:], d[2:], d[3:]), p[4:]):
        if t not in seen:
            total[t] += val % 10
            seen.add(t)

print(max(total.values()))
