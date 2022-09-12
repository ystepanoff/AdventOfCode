import math

def check(x, y, n):
    return x * x + x * y + 41 * y * y <= n

N = 10 ** 16
L = int(math.pow(4 * N  / 163, 0.5))
total = 0
for y in range(-L, L + 1):
    s = int(math.pow(4 * N - 163 * y * y, 0.5))
    l = (-s - y) // 2
    r = (s - y) // 2
    total += r - l + 1
    if not check(l, y, N):
        total -= 1
    if not check(r, y, N):
        total -= 1
print(total - 1)
