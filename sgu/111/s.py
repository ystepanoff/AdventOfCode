x = int(input())
l, r = 1, x + 1
while r - l > 1:
    m = (l + r) >> 1
    if m * m > x:
        r = m
    else:
        l = m
print(l)
