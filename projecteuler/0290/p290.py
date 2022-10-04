from collections import defaultdict


def sumd(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s


for n in range(1, 6):
    cnt = len([1 for i in range(10 ** n) if sumd(i) == sumd(137 * i)])
    print(n, cnt)


CACHE = defaultdict(int)


def f(n, a, b):
    if n == 1:
        return len([1 for n in range(10) if sumd(n) == sumd(137 * n + a) + b])
    if (n, a, b) not in CACHE:
        total = 0
        for y in range(10):
            total += f(n - 1, (137 * y + a) // 10, b - y + (137 * y + a) % 10)
        CACHE[n, a, b] = total
    return CACHE[n, a, b]


for n in range(1, 18 + 1):
    print(n, f(n, 0, 0))
