import sys
from collections import defaultdict

G = {
    i + j*1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}

beams = defaultdict(int)
beams[next(k for k, v in G.items() if v == 'S')] = 1
while beams.keys() & G.keys():
    for b in list(beams.keys() & G.keys()):
        count = beams.pop(b)
        if G[b] == '^':
            beams[b - 1j] += count
            beams[b + 1j] += count
        else:
            beams[b + 1] += count
print(sum(beams.values()))
