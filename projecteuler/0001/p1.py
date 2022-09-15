N = 1000


def summ(n, k):
    m = n // k
    return k * m * (m + 1) // 2


print(summ(N, 3) + summ(N, 5) - summ(N, 15))
