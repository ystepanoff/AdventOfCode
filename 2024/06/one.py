import sys


def count(grid, pos):
    s, d = set(), -1
    while True:
        s.add(pos)
        p = pos + d
        if p not in grid:
            return len(s)
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


print(count(G, start))
