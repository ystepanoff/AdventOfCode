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
curr = 0
abyss = False
while not abyss:
    curr += 1
    x, y = 0, 500
    while True:
        if x > max_depth:
            abyss = True
            break
        if grid[x + 1][y] == 0:
            x += 1
        elif grid[x + 1][y - 1] == 0:
            x += 1
            y -= 1
        elif grid[x + 1][y + 1] == 0:
            x += 1
            y += 1
        else:
            grid[x][y] = 2
            break
print(curr - 1)
