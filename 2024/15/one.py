import sys

G, W = set(), set()
d = {'v': 1, '<': -1j, '^': -1, '>': 1j}
m, n = 0, 0
for i, line in enumerate(sys.stdin):
    line = line.rstrip()
    if not line:
        break
    for j, ch in enumerate(line):
        n = max(n, j + 1)
        if ch == '@':
            r = i + j * 1j
        elif ch == '#':
            W.add(i + j * 1j)
        elif ch == 'O':
            G.add(i + j * 1j)
    m = i + 1
moves = ""
for line in sys.stdin:
    moves += line.rstrip()


def move(x, dx):
    if x in W or x not in G:
        return
    move(x + dx, dx)
    if x in G and x + dx not in G and x + dx not in W:
        G.discard(x)
        G.add(x + dx)


for i, ch in enumerate(moves):
    if r + d[ch] not in W:
        move(r + d[ch], d[ch])
    if r + d[ch] not in G and r + d[ch] not in W:
        r += d[ch]

total = 0
for i in range(m):
    for j in range(n):
        if i + j * 1j in G:
            total += i * 100 + j
print(total)
