cycles = {20, 60, 100, 140, 180, 220}
x, c = 1, 1
grid = [['.' for _ in range(40)] for _ in range(6)]
total = 0 
for line in open('input'):
    line = line.strip()
    if line.startswith('noop'):
        c += 1
        row, pos = (c // 40), c % 40
        if pos in [x, x + 1, x + 2]:
            grid[row][pos - 1] = '#'
    else:
        _, n = line.split()
        n = int(n)
        c += 1
        row, pos = (c // 40), c % 40
        if pos in [x, x + 1, x + 2]:
            grid[row][pos - 1] = '#'
        c += 1
        x += n
        row, pos = (c // 40), c % 40
        if pos in [x, x + 1, x + 2]:
            grid[row][pos - 1] = '#'
        if c in cycles:
            total += c * x
for s in grid:
    print(''.join(s))
