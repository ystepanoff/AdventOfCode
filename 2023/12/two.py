import sys


CACHE = {}


def dp(arr, groups, i, j, curr):
    global CACHE
    key = (i, j, curr)
    if key in CACHE:
        return CACHE[key]
    if i == len(arr):
        if j == len(groups) and curr == 0:
            return 1
        elif j == len(groups) - 1 and groups[j] == curr:
            return 1
        else:
            return 0
    total = 0
    if arr[i] == '.':
        if curr == 0:
            total += dp(arr, groups, i + 1, j, 0)
        elif j < len(groups) and groups[j] == curr:
            total += dp(arr, groups, i + 1, j + 1, 0)
    elif arr[i] == '#':
        total += dp(arr, groups, i + 1, j, curr + 1)
    elif arr[i] == '?':
        total += dp(arr, groups, i + 1, j, curr + 1)
        if curr == 0:
            total += dp(arr, groups, i + 1, j, 0)
        elif j < len(groups) and groups[j] == curr:
            total += dp(arr, groups, i + 1, j + 1, 0)
    CACHE[key] = total
    return total


total = 0
for line in sys.stdin:
    arr, groups = line.rstrip().split()
    arr = '?'.join([arr] * 5)
    groups = ','.join([groups] * 5)
    arr = list(arr)
    groups = [int(g) for g in groups.split(',')]
    CACHE.clear()
    total += dp(arr, groups, 0, 0, 0)
print(total)
