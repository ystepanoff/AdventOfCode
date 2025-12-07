import sys

G = {
    i + j*1j: ch
    for i, line in enumerate(sys.stdin)
    for j, ch in enumerate(line.rstrip())
}

s = list(G.keys())[list(G.values()).index('S')]
total, beams, seen = 0, { s }, set()
while beams & G.keys():
    for b in beams & G.keys():
        beams.discard(b)
        match G[b]:
            case '.' | 'S':
                beams.add(b + 1)
            case '^':
                beams.add(b - 1j)
                beams.add(b + 1j)
                if b not in seen:
                    total += 1
                    seen.add(b)
print(total)
