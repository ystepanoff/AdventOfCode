import sys

keys, locks = [], []
curr = []
for line in list(sys.stdin) + ['']:
    line = line.rstrip()
    if not line:
        (keys if curr[0][0] == '#' else locks).append([r.count('#') for r in zip(*curr)])
        curr = []
        continue
    curr.append(list(line))

print(sum(all(x + y < 8 for x, y in zip(k, l)) for k in keys for l in locks))
