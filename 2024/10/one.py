import sys


G = {
    i + j * 1j: int(ch)
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
    if ch.isdigit()
}


def travel(curr):
    if G[curr] == 9:
        NINES.add(curr)
    d = 1
    for i in range(4):
        c = curr + d
        if c in G and G[c] == G[curr] + 1:
            travel(c)
        d *= -1j


s = 0
for x, y in G.items():
    if y == 0:
        NINES = set()
        travel(x)
        s += len(NINES)
print(s)
