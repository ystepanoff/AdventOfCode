import sys

G = {
    i + j * 1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}
VISITED = set()


def paint(x):
    VISITED.add(x)
    sides, s, d = set(), 1, 1
    for _ in range(4):
        if x + d in G:
            if G[x + d] == G[x]:
                if x + d not in VISITED:
                    s_, sides_ = paint(x + d)
                    s += s_
                    sides.update(sides_)
            else:
                sides.add((x, d))
        else:
            sides.add((x, d))
        d *= -1j
    return s, sides


total = 0
for v in G:
    if v not in VISITED:
        s, sides = paint(v)
        sub = 0
        for x, d in sides:
            if (x + d * 1j, d) in sides:
                sub += 1
        total += s * (len(sides) - sub)
print(total)
