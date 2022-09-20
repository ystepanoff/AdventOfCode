import math


def rec(cubes, primes, n, p_i, phi2):
    r = 0
    if phi2 in cubes:
        r = 1
    for i in range(p_i):
        p = primes[i]
        p2 = p * p
        phi2_new = phi2 * (p2 - p)
        k = n // p
        l = p
        while k > 0:
            r += l * rec(cubes, primes, k, i, phi2_new)
            phi2_new *= p2
            k //= p
            l *= p
    return r


def p342(N=10**10):
    M = int(math.sqrt(N))
    primes, sieve = [], [True] * M
    for i in range(2, M):
        if sieve[i]:
            primes.append(i)
            for j in range(i + i, M, i):
                sieve[j] = False
    cubes = set()
    i = 1
    while i * i * i < N * N:
        cubes.add(i * i * i)
        i += 1
    s = 0
    for i, p in enumerate(primes):
        p2 = p * p
        p3 = p2 * p
        p6 = p3 * p3
        phi2 = p3 * (p - 1)
        K = N // p2
        L = p2
        while K > 0:
            s += L * rec(cubes, primes, K, i, phi2)
            phi2 *= p6
            K //= p3
            L *= p3
    return s


if __name__ == '__main__':
    print(p342())
