from itertools import product
import sys


def evaluate(a, ops):
    result = a[0]
    for i, op in enumerate(ops):
        match op:
            case '+':
                result += a[i+1]
            case '*':
                result *= a[i+1]
            case '|':
                result = result * (10 ** len(str(a[i+1]))) + a[i+1]
    return result


total = 0
for line in sys.stdin:
    line = line.rstrip()
    m, a = line.split(': ')
    m = int(m)
    a = [int(x) for x in a.split()]
    for ops in product("+*|", repeat=len(a) - 1):
        if evaluate(a, ops) == m:
            total += m
            break

print(total)
