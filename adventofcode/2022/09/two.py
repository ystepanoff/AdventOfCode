s = lambda x: (x > 0) - (x < 0)
sigma = lambda z: s(z.real) + s(z.imag) * 1j
dirs = {
    'L': -1,
    'R': 1,
    'U': 1j,
    'D': -1j
}
snake = [0 for _ in range(10)]
visited = set()
for line in open('input'):
    d, n = line.strip().split()
    d, n = dirs[d], int(n)
    for _ in range(n):
        snake[0] += d
        for i in range(1, 10):
            xy = snake[i - 1] - snake[i]
            if abs(xy) >= 2:
                snake[i] += sigma(xy)
        visited.add(snake[-1])
print(len(visited))
