def is_pal(n):
    d = []
    while n > 0:
        d.append(n % 10)
        n //= 10
    return d == d[::-1]


best = 0
for a in range(100, 1000):
    for b in range(100, 1000):
        c = a * b
        if is_pal(c):
            best = max(best, c)
print(best)
