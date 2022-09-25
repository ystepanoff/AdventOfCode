LIMIT = (10 ** 8) * 2
primes, sieve = [], [True] * LIMIT
for i in range(2, LIMIT):
    if sieve[i]:
        primes.append(i)
        for j in range(i + i, LIMIT, i):
            sieve[j] = False

psq = { p * p for p in primes }
total = 0
s = 0
for p in primes:
    n = p * p
    m = int(str(n)[::-1])
    if n != m and m in psq:
        total += 1
        if total > 50:
            break
        s += n
        print(n)
print("sum =", s)
