def f(n):
    b = format(n, '06b')
    return int(b[1:] + str(int(b[0]) ^ (int(b[1]) & int(b[2]))), 2)

used = set()
for i in range(2 ** 6):
    if i in used:
        continue
    used.add(i)
    l = 1
    curr, next = i, f(i)
    while next != i:
        used.add(next)
        l += 1
        curr, next = next, f(next)
    print(l)
