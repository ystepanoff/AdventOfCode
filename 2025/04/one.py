import sys

G = {
    i + j*1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}

D = [a + b*1j for a in (-1, 0, 1) for b in (-1, 0, 1) if a or b]

print(
    sum(
        sum(G.get(z + d) == '@' for d in D) < 4
        for z, c in G.items()
        if c == '@'
    )
)
