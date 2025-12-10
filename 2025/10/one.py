import sys
import re


total = 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    ind = re.search(r'\[([.#]+)\]', line).group(1)
    target = sum(1 << i for i, c in enumerate(ind) if c == '#')
    btns = [sum(1 << int(i) for i in m.group(1).split(',')) for m in re.finditer(r'\(([^)]+)\)', line)]
    q, d = [0], {0: 0}
    for u in q:
        for b in btns:
            v = u ^ b
            if v not in d:
                q.append(v)
                d[v] = d[u] + 1
    total += d[target]
print(total)
