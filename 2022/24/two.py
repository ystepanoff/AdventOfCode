grid = [line.rstrip() for line in open('input') if line.rstrip()]
n, m = len(grid), len(grid[0])
bad = {}
for t in range(n * m * 2):
    bad[t] = set()
    for i, row in enumerate(grid):
        for j, c in enumerate(row):
            match c:
                case '#':
                    bad[t].add((i, j))
                case '>':
                    bad[t].add((i, 1 + (j + t - 1) % (m - 2)))
                case '<':
                    bad[t].add((i, 1 + (j - t - 1) % (m - 2)))
                case '^':
                    bad[t].add((1 + (i - t - 1) % (n - 2), j))
                case 'v':
                    bad[t].add((1 + (i + t - 1) % (n - 2), j))
key = (0, grid[0].index('.'), 0, False, False)
d = [(0, 0), (0, 1), (0, -1), (1, 0), (-1, 0)]
q, vis = [key], {key}
for x, y, t, a, b in q:
    if x == n - 1:
        if a and b:
            print(t)
            break
        a = True
    if x == 0:
        if a:
            b = True
    for dx, dy in d:
        key = (x + dx, y + dy, t + 1, a, b)
        if key[0] < 0 or key[1] < 0 or key[0] >= n or key[1] >= m or key in vis:
            continue
        if key[:2] not in bad[t + 1]:
            q.append(key)
            vis.add(key)
