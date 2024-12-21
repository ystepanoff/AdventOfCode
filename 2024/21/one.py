from itertools import permutations
from sys import stdin


K = {
    key: (i, j)
    for i, row in enumerate(['789', '456', '123', ' 0A'])
    for j, key in enumerate(row)
}
A = {
    key: (i, j)
    for i, row in enumerate([' ^A', '<v>'])
    for j, key in enumerate(row)
}


def f(s, coords, steps):
    if steps == 0:
        path = [coords['A']] + [coords[c] for c in s]
        return sum(
            abs(x1 - x0) + abs(y1 - y0) + 1
            for (x0, y0), (x1, y1) in zip(path, path[1:])
        )
    total = 0
    cx, cy = coords['A']
    for c in s:
        x, y = coords[c]
        curr = "<>"[y > cy] * abs(y - cy) + "^v"[x > cx] * abs(x - cx)
        best = float('inf')
        for p in permutations(curr):
            nx, ny = cx, cy
            for d in p:
                nx += (d == 'v') - (d == '^')
                ny += (d == '>') - (d == '<')
                if (nx, ny) == coords[' ']:
                    break
            else:
                best = min(f(''.join(p) + 'A', A, steps - 1), best)
        total += best
        cx, cy = x, y
    return total


total = 0
for line in stdin:
    line = line.rstrip()
    total += int(line[:-1]) * f(line, K, 2)
print(total)
