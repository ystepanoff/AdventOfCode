from functools import cache
from itertools import permutations
from sys import stdin


COORDS = [
    {
        key: (i, j)
        for i, row in enumerate(['789', '456', '123', ' 0A'])
        for j, key in enumerate(row)
    },
    {
        key: (i, j)
        for i, row in enumerate([' ^A', '<v>'])
        for j, key in enumerate(row)
    }
]


@cache
def f(s, idx, steps):
    if steps == 0:
        path = [COORDS[idx]['A']] + [COORDS[idx][c] for c in s]
        return sum(
            abs(x1 - x0) + abs(y1 - y0) + 1
            for (x0, y0), (x1, y1) in zip(path, path[1:])
        )
    total = 0
    cx, cy = COORDS[idx]['A']
    for c in s:
        x, y = COORDS[idx][c]
        curr = "<>"[y > cy] * abs(y - cy) + "^v"[x > cx] * abs(x - cx)
        best = float('inf')
        for p in permutations(curr):
            nx, ny = cx, cy
            for d in p:
                nx += (d == 'v') - (d == '^')
                ny += (d == '>') - (d == '<')
                if (nx, ny) == COORDS[idx][' ']:
                    break
            else:
                best = min(f(''.join(p) + 'A', 1, steps - 1), best)
        total += best
        cx, cy = x, y
    return total


total = 0
for line in stdin:
    line = line.rstrip()
    total += int(line[:-1]) * f(line, 0, 25)
print(total)
