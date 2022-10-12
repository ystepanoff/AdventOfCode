a = [0, 0, 1, 0, 2, 1, 4, 3, 9, 7]
i = len(a)
while a[-1] != 0:
    a.append((3 * a[i - 2] + a[i - 3] - 2 * a[i - 4] - 2 * a[i - 5]) % (10 ** 6))
    i += 1
print(i - 1)
