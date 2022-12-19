def is_root(n: int, x: int) -> bool:
    s, p = n % 10, 1
    while n > 0:
        n //= 10
        p *= x
        s += p * (n % 10)
    return s == 0


DIG = set()


def good(n: int) -> bool:
    for i in range(10):
        if is_root(n, i) or is_root(n, -i):
            DIG.add(i)
            return True
    return False


total = 0
for n in range(1, 1001):
    if good(n):
        print(n)
        total += 1
print(total)
print(DIG)
