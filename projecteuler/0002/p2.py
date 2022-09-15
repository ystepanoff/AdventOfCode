total = 0
a, b = 1, 1
while a + b <= 4 * (10 ** 6):
    if (a + b) % 2 == 0:
        total += a + b
    a, b = b, a + b
print(total)
