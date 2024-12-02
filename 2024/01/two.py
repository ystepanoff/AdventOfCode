import sys

a, b = [], []
for line in sys.stdin:
    x, y = map(int, line.split())
    a.append(x)
    b.append(y)

a.sort()
b.sort()

total = 0
for x in a:
    total += b.count(x) * x

print(total)
