N = 1000
grid = [[0 for _ in range(N)] for _ in range(N)]
max_depth = 0
for line in open('input'):
    line = line.rstrip()
    if line:
        path = line.split(' -> ')
        path = list(map(lambda c: tuple(map(int, c.split(',')[::-1])), path))
        for i in range(1, len(path)):
            from_x, from_y = path[i - 1]
            to_x, to_y = path[i]
            if from_x == to_x:
                for y in range(min(from_y, to_y), max(from_y, to_y) + 1):
                    grid[from_x][y] = 1
            elif from_y == to_y:
                for x in range(min(from_x, to_x), max(from_x, to_x) + 1):
                    grid[x][from_y] = 1
            max_depth = max(max_depth, max(from_x, to_x))
for i in range(N):
    grid[max_depth + 2][i] = 1
curr = 0
while True:
    curr += 1
    x, y = 0, 500
    stable = False
    while True:
        if grid[x + 1][y] == 0:
            x += 1
        elif grid[x + 1][y - 1] == 0:
            x += 1
            y -= 1
        elif grid[x + 1][y + 1] == 0:
            x += 1
            y += 1
        else:
            if (x, y) == (0, 500):
                stable = True
            grid[x][y] = 2
            break
    if stable:
        break
print(curr)
