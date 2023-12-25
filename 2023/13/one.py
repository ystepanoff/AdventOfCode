import sys


def candidates(row):
    n = len(row)
    cand = set()
    for i in range(n - 1):
        l, r = i, i + 1
        while l >= 0 and r < n and row[l] == row[r]:
            l -= 1
            r += 1
        if l == -1 or r == n:
            cand.add(i + 1)
    return cand


def transpose(a):
    n, m = len(a), len(a[0])
    b = [[a[i][j] for i in range(n)] for j in range(m)]
    return b


def solve(pattern):
    cand = list(set.intersection(*[candidates(row) for row in pattern]))
    if len(cand) != 1:
        pattern = transpose(pattern)
        cand = list(set.intersection(*[{x * 100 for x in candidates(row)} for row in pattern]))
    assert len(cand) == 1
    return cand[0]


total = 0
pattern = []
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        total += solve(pattern)
        pattern = []
    else:
        pattern.append(list(line))
if pattern:
    total += solve(pattern)
print(total)
