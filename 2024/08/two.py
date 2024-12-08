import sys
from itertools import combinations
from collections import defaultdict

m, n = 0, 0
antennas = defaultdict(list)
for i, line in enumerate(sys.stdin):
    line = line.rstrip()
    m = i + 1
    for j, ch in enumerate(line):
        if ch != '.':
            antennas[ch].append((i, j))
        n = max(n, j + 1)

antinodes = {
    cand
    for positions in antennas.values()
    for a, b in combinations(positions, 2)
    for k in range(max(m, n))
    for cand in [(a[0] - k * (b[0] - a[0]), a[1] - k * (b[1] - a[1])),
                 (b[0] + k * (b[0] - a[0]), b[1] + k * (b[1] - a[1]))]
    if 0 <= cand[0] < m and 0 <= cand[1] < n
}
print(len(antinodes))
