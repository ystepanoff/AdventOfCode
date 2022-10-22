from bisect import bisect

N = 10 ** 17
FIB = [1, 2]
while FIB[-1] + FIB[-2] < N:
    FIB.append(FIB[-1] + FIB[-2])

CACHE = {}


def z(n: int) -> int:
    if n not in CACHE:
        CACHE[n] = 0 if n == 0 else 1 + z(n - FIB[bisect(FIB, n) - 1])
    return CACHE[n]


def Z(n: int) -> int:
    if n < 3:
        return n
    rest = 1
    if n not in FIB:
        f = FIB[bisect(FIB, n) - 1]
        rest += Z(n - f) + n - f
        n = f
    a, b = 2, 3
    for i in range(2, len(FIB)):
        if FIB[i] >= n:
            break
        c = FIB[i] + a
        a, b = a + b, c
    return a + rest


print(Z(N - 1))
