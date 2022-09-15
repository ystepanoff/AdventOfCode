def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(a, b)


r = 1
for i in range(2, 21):
    r = lcm(r, i)
print(r)
