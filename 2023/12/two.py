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
    for c in '.#':
        if arr[i] in [c, '?']:
            if c == '.' and curr == 0:
                total += dp(arr, groups, i + 1, j, 0)
            elif c == '.' and curr > 0 and j < len(groups) and groups[j] == curr:
                total += dp(arr, groups, i + 1, j + 1, 0)
            elif c == '#':
                total += dp(arr, groups, i + 1, j, curr + 1)
    CACHE[key] = total
    return total
        

total = 0
for line in sys.stdin:
    line = line.rstrip()
    arr, groups = line.split()
    arr = '?'.join([arr] * 5)
    groups = ','.join([groups] * 5)
    arr = list(arr)
    groups = [int(g) for g in groups.split(',')]
    CACHE = {}
    total += dp(arr, groups, 0, 0, 0)
print(total)
