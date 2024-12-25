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

check = lambda x, y: 0 <= x < m and 0 <= y < n
antinodes = set()
for freq in antennas.values():
    for a, b in combinations(freq, 2):
        if a > b:
            a, b = b, a
        dx = b[0] - a[0]
        dy = b[1] - a[1]
        cand1 = (a[0] - dx, a[1] - dy)
        cand2 = (b[0] + dx, b[1] + dy)
        if check(*cand1):
            antinodes.add(cand1)
        if check(*cand2):
            antinodes.add(cand2)
print(len(antinodes))
