from math import sqrt
from sympy import primepi

N = 10000000000
M = int(sqrt(N))

total = 0
for y in range(1, M + 1):
    total += primepi(N // y) - primepi(y - 1)
print(N - total)
