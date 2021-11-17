n = int(input())
l, r = 1, 10 ** 600
while l < r:
    m = (l + r) >> 1
    s = (m * (m + 1)) // 2
    if s == n:
        print(m)
        break
    if s > n:
        r = m
    else:
        l = m + 1
