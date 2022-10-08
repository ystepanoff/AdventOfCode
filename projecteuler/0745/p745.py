from math import sqrt

def S(n):
    m = int(sqrt(n))
    ff = [0] * (m + 1)
    for i in range(m, 0, -1):
        ff[i] = n // (i * i) - sum([ff[i * j] for j in range(2, int(sqrt(n) / i) + 1)])
    return sum([i * i * ff[i] for i in range(1, m + 1)])

n = 10 ** 14
print(S(n) % (10 ** 9 + 7))
