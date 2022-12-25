DIGITS = {
    '2': 2,
    '1': 1,
    '0': 0,
    '-': -1,
    '=': -2,
}


def from_snafu(s):
    return sum(DIGITS[c] * (5 ** i) for i, c in enumerate(s[::-1]))


def to_snafu(n):
    alpha = {v: c for c, v in DIGITS.items()}
    s = ''
    while n > 0:
        r = n % 5
        if r == 3:
            r = -2
            n += 2
        elif r == 4:
            r = -1
            n += 1
        n //= 5
        s = alpha[r] + s
    return s

  
total = 0
for line in open('input'):
    total += from_snafu(line.rstrip())
print(to_snafu(total))

