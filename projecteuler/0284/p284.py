alpha = "0123456789abcde"


def to14(n):
    s = ""
    while n > 0:
        s += alpha[n % 14]
        n //= 14
    return s[::-1]


def from14(s):
    n = 0
    for c in s:
        n = n * 14 + alpha.index(c)
    return n


for n in range(1, 10):
    p = 7 ** n

    a = 1
    while a * p < 14 ** n:
        if (a * p - 1) % (2 ** n) == 0:
            s = to14(a * p)
            print(s)
        a += 1

    b = 1
    while b * p + 1 < 14 ** n:
        if (b * p + 1) % (2 ** n) == 0:
            s = to14(b * p + 1)
            print(s)
        b += 1


def next(s):
    l = len(s) + 1
    p2 = 2 ** l
    p7 = 7 ** l
    for c in alpha:
        t = c + s
        n = from14(t)
        if (n % p2 == 0 and (n - 1) % p7 == 0) or \
           (n % p7 == 0 and (n - 1) % p2 == 0):
            return t
    return None


def sumd(case_file, n):
    with open(case_file, 'rt') as file:
        s = file.readline().strip()
        assert len(s) == 10000, "something is wrong"
        s = s[::-1]
        total = 0
        for i in range(n):
            if s[i] == '0':
                continue
            for j in range(i + 1):
                total += from14(s[j])
    return total


print(to14(sumd('a.txt', 10000) + sumd('b.txt', 10000) + 1))
