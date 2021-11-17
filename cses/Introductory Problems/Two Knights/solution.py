N = int(input())
for n in range(1, N + 1):
    print((n - 1) * (n + 4) * (n * n - 3 * n + 4) // 2)
