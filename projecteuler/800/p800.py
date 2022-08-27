# p^q * q^p <= N
# q * log(p) + p * log(q) <= log(N)

import math

primes = []
sieve = [False] * (10 ** 8)
for i in range(2, 10 ** 8):
    if not sieve[i]:
        primes.append(i)
        j = 2
        while j * i < 10 ** 8:
            sieve[j * i] = True
            j += 1

logN = 800800 * math.log(800800.0)
total = 0
for i, p in enumerate(primes):
    l, r = i, len(primes) - 1
    while r - l > 1:
        m = (l + r) >> 1
        if p * math.log(primes[m]) + primes[m] * math.log(p) <= logN:
            l = m
        else:
            r = m
    q = primes[l]
    total += l - i
print(total)
