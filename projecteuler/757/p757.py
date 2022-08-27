N = 10 ** 14
M = int(N ** (1.0 / 4))
S = set()
for x in range(1, M + 1):
    y = x
    while True:
        z = x * (x + 1) * y * (y + 1)
        if z > N:
            break
        S.add(z)
        y += 1
print(len(S))
