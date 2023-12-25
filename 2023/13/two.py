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


def solve(pattern, banned=-1):
    cand = list(set.intersection(*[candidates(row) for row in pattern]))
    pattern = transpose(pattern)
    cand.extend(list(set.intersection(*[{x * 100 for x in candidates(row)} for row in pattern])))
    return cand

# Don't forget to add a newline to the input file!


total = 0
pattern = []
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        old_line = solve(pattern)[0]
        result = set()
        for i in range(len(pattern)):
            for j in range(len(pattern[0])):
                pattern[i][j] = '#' if pattern[i][j] == '.' else '.'
                new_lines = solve(pattern)
                new_lines = [x for x in new_lines if x != old_line]
                if len(new_lines) == 1:
                    result.add(new_lines[0])
                pattern[i][j] = '#' if pattern[i][j] == '.' else '.'
        result = list(result)
        assert len(result) == 1
        if len(result) > 0: total += result[0]
        pattern = []
    else:
        pattern.append(list(line))
print(total)
