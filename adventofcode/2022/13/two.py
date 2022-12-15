import json
from itertools import zip_longest
from functools import cmp_to_key


def compare(a, b):
    if isinstance(a, int) and isinstance(b, int):
        return a - b
    if isinstance(a, int) and isinstance(b, list):
        a = [a]
    if isinstance(a, list) and isinstance(b, int):
        b = [b]
    for x, y in zip_longest(a, b):
        if x is None:
            return -1
        if y is None:
            return 1
        cmp = compare(x, y)
        if cmp != 0:
            return cmp
    else:
        return 0


packets = []
for idx, line in enumerate(open('input')):
    line = line.rstrip()
    if line:
        packets.append(json.loads(line))
packets.extend([[[2]], [[6]]])
packets = sorted(packets, key=cmp_to_key(compare))
print((packets.index([[2]]) + 1) * (packets.index([[6]]) + 1))
