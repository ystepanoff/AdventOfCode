import sys

G = {}
steps = 64 + 1

for i, line in enumerate(sys.stdin):
    line = line.strip()
    if not line:
        continue
    for j, c in enumerate(line):
        G[i + 1j * j] = c

n = int(len(G) ** 0.5)

def bruteforce(steps):
    grid = G.copy()
    steps += 1
    while (steps := steps - 1):
        new_grid = G.copy()
        for pos in grid:
            if grid[pos] not in ['S', 'O']:
                continue
            for dir in [-1, 1, -1j, 1j]:
                new_pos = pos + dir
                new_pos_t = new_pos.real % n + new_pos.imag % n * 1j
                if new_pos_t in G and G[new_pos_t] != '#':
                    new_grid[new_pos] = 'O'
            new_grid[pos] = '.'
        grid = new_grid.copy()
    return sum(1 for pos in grid if grid[pos] == 'O')


def fit_quadratic(xs, ys):
    a = (ys[-1] - 2 * ys[-2] + ys[-3]) / (xs[-1] ** 2 - 2 * xs[-2] ** 2 + xs[-3] ** 2)
    b = (ys[-1] - ys[-2] - a * xs[-1] ** 2 + a * xs[-2] ** 2) / (xs[-1] - xs[-2])
    c = ys[-1] - a * xs[-1] ** 2 - b * xs[-1]
    return a, b, c


total_steps = 26501365
x, y = total_steps // n, total_steps % n
assert y == n // 2

xs, ys = [], []
for i in range(3):
    xs.append(n * i + y)
    ys.append(bruteforce(n * i + y))
a, b, c = fit_quadratic(xs, ys)
print(int(a * total_steps ** 2 + b * total_steps + c))
