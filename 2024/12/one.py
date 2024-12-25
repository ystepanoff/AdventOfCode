import sys

G = {
    i + j * 1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}
VISITED = set()


def paint(x):
    VISITED.add(x)
    p, s, d = 0, 1, 1
    for _ in range(4):
        if x + d in G:
            if G[x + d] == G[x]:
                if x + d not in VISITED:
                    s_, p_ = paint(x + d)
                    s += s_
                    p += p_
            else:
                p += 1
        else:
            p += 1
        d *= -1j
    return s, p


total = 0
for v in G:
    if v not in VISITED:
        s, p = paint(v)
        total += s * p
print(total)
