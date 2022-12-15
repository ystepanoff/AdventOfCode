import json
from itertools import zip_longest


def compare(a, b):
    if isinstance(a, int) and isinstance(b, int):
        return a < b
    if isinstance(a, int) and isinstance(b, list):
        a = [a]
    if isinstance(a, list) and isinstance(b, int):
        b = [b]
    for x, y in zip_longest(a, b):
        if x is None:
            return True
        if y is None:
            return False
        if x != y:
            return compare(x, y)


total, curr = 0, 0
for idx, line in enumerate(open('input')):
    line = line.rstrip()
    if idx % 3 == 0:
        first = json.loads(line)
    elif idx % 3 == 1:
        second = json.loads(line)
        curr += 1
        if compare(first, second):
            total += curr
print(total)
