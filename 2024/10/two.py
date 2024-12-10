import sys


G = {
    i + j * 1j: int(ch)
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
    if ch.isdigit()
}


def travel(curr):
    if G[curr] == 9:
        return 1
    s, d = 0, 1
    for i in range(4):
        c = curr + d
        if c in G and G[c] == G[curr] + 1:
            s += travel(c)
        d *= -1j
    return s


s = 0
for x, y in G.items():
    if y == 0:
        s += travel(x)
print(s)
