import sys


def gen(n):
    m = ((n << 6) ^ n) & 0xFFFFFF
    m = ((m >> 5) ^ m) & 0xFFFFFF
    return ((m << 11) ^ m) & 0xFFFFFF


total = 0
for line in sys.stdin:
    n = int(line)
    p = [n] + [n := gen(n) for _ in range(2000)]
    total += p[-1]
print(total)
