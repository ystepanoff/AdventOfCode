limit = 10001


def is_prime(x):
    c = 2
    while c * c <= x:
        if x % c == 0:
            return False
        c += 1
    return True


c, i = 0, 2
while c < limit:
    if is_prime(i):
        c += 1
    i += 1
print(i - 1)
