import sys


def process(lst):
    if all(x == 0 for x in lst):
        return 0
    diffs = [lst[i] - lst[i - 1] for i in range(1, len(lst))]
    return process(diffs) + lst[-1]


total = 0
for line in sys.stdin:
    line = line.rstrip()
    lst = [int(x) for x in line.split()][::-1]
    total += process(lst)
print(total)
