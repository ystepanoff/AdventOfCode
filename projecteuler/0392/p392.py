from math import sqrt


def f(x: float) -> float:
    return sqrt(1 - x * x)


def S(n: int, x1: float) -> float:
    x = [0, x1]
    y = [1, f(x1)]
    s = y[0] * x1
    for i in range(1, n + 1):
        xnext = (x[i] ** 2 - y[i] ** 2 + y[i - 1] * y[i]) / x[i]
        if xnext > 1:
            return float('inf')
        s += (xnext - x[i]) * y[i]
        x.append(xnext)
        y.append(f(xnext))
    return s * 4


N = 400
l, r = 0, 1.0
while r - l > 1e-12:
    m = (l + r) / 2
    if S(N // 2, m) == float('inf'):
        r = m
    else:
        l = m
print("{:.10f}".format(S(N // 2, l)))
