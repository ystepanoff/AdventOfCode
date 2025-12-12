from functools import reduce
import operator
import sys

ops = {
    '*': operator.mul,
    '+': operator.add,
}

lines = [line.rstrip('\n') for line in sys.stdin]
width = max(len(line) for line in lines)
lines = [line.ljust(width) for line in lines]

total = 0
res, op = [], None
for col in range(width - 1, -1, -1):
    chars = [line[col] for line in lines]
    if all(c == ' ' for c in chars):
        total += reduce(ops[op], res)
        res, op = [], None
    else:
        op = chars[-1]
        res.append(int(''.join(c for c in chars[:-1] if c != ' ')))
print(total + reduce(ops[op], res))
