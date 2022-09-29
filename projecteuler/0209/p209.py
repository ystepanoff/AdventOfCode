def f(n):
    b = format(n, '06b')
    return int(b[1:] + str(int(b[0]) ^ (int(b[1]) & int(b[2]))), 2)


c = [0, 1, 3]
for i in range(3, 100):
    c.append(c[i - 1] + c[i - 2])
result = 1
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
    result *= c[l]
print(result)
