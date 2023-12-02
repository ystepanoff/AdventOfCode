import sys
import re

total = 0
for line in sys.stdin:
    line = line.rstrip()
    rest = re.split('(?<=Game\s)\d+:\s', line)[-1]
    r, g, b = 0, 0, 0
    for group in rest.split('; '):
        for balls in re.split(', ', group):
            n, c = re.split(' ', balls)
            if c == 'red': r = max(r, int(n))
            if c == 'green': g = max(g, int(n))
            if c == 'blue': b = max(b, int(n))
    total += r * g * b
print(total)
