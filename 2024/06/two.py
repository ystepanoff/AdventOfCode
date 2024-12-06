import sys


def loop(grid, pos):
    s, d = set(), -1
    while True:
        if (pos, d) in s:
            return True
        s.add((pos, d))
        p = pos + d
        if p not in grid:
            return False
        if grid[p] not in ".^":
            d *= -1j
            continue
        pos = p


G = {
    i + j * 1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}
start = list(G.keys())[list(G.values()).index('^')]

total = 0
for x in G:
    if G[x] == '.':
        G[x] = '#'
        if loop(G, start):
            total += 1
        G[x] = '.'
print(total)
