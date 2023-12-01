import sys

total = 0
for line in sys.stdin:
    d = []
    for c in line:
        if c.isdigit():
            d.append(int(c))
    total += d[0] * 10 + d[-1]
print(total)
