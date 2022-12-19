def powmod(a, b, m):
    r = 1
    while b > 0:
        if b % 2 == 1:
            r = (r * a) % m
            b -= 1
        a = (a * a) % m
        b >>= 1
    return r


def f(n):
    if n % 10 == 0:
        return 0
    r = n
    for i in range(12):
        r = powmod(n, r, 10 ** (i + 1))
    s = str(r)
    m = 0
    for i, c in enumerate(reversed(s)):
        if c == '0':
            break
        m += int(c) * (10 ** i)
    return m


print(f(4))
print(f(157))
print(sum(f(i) for i in range(2, 1001)))
