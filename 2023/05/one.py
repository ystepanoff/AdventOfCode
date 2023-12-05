from collections import defaultdict
import sys

order = ['seed', 'soil', 'fertilizer', 'water', 'light', 'temperature', 'humidity', 'location']

rules = defaultdict(list)
seeds = []

for line in sys.stdin:
    line = line.rstrip()
    if line.startswith('seeds'):
        seeds = map(int, line.split(': ')[1].split())
        continue
    if not line:
        src, dst = None, None
        continue
    if line.endswith('map:'):
        src, dst = line.split()[0].split('-to-')
        continue
    if src is not None and dst is not None:
        d_start, s_start, length = map(int, line.split())
        rules[src].append((s_start, dst, d_start, length))

best = 1e12

for seed in seeds:
    v = ('seed', seed)
    while v[0] != 'location':
        v_new = v
        for s_start, dst, d_start, length in rules[v[0]]:
            if s_start <= v[1] and v[1] < s_start + length:
                v_new = (dst, d_start + v[1] - s_start)
        if v_new == v:
            v_new = (order[order.index(v[0]) + 1], v[1])
        v = v_new
    best = min(best, v[1])

print(best)
