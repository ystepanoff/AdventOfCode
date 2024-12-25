import re
import sys


VISITED = set()
def walk(G, x):
    VISITED.add(x)
    d = -1
    for _ in range(4):
        if x + d in G and x + d not in VISITED:
            walk(G, x + d)
        d *= -1j


w, h = 101, 103
robots = [tuple(map(int, re.findall(r"-?\d+", line))) for line in sys.stdin]

steps = 0
while True:
    r = [((x + vx * steps) % w, (y + vy * steps) % h, vx, vy) for x, y, vx, vy in robots]
    G = set()
    for x, y, _, _ in r:
        G.add(x + y * 1j)
    best = 0
    for x in G:
        VISITED = set()
        if not x in VISITED:
            walk(G, x)
            best = max(best, len(VISITED))
    if best > 100:
        print(steps)
        break
    steps += 1
