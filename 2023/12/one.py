import sys


def get_groups(arr):
    groups = []
    curr = 0
    if arr[0] == '#':
        curr = 1
    for i in range(1, len(arr)):
        if arr[i] == '#':
            curr += 1
        else:
            if curr > 0:
                groups.append(curr)
            curr = 0
    if curr > 0:
        groups.append(curr)
    return groups

total = 0
for line in sys.stdin:
    line = line.rstrip()
    arr, groups = line.split()
    arr = list(arr)
    groups = [int(g) for g in groups.split(',')]
    idx = []
    for i, ch in enumerate(arr):
        if ch == '?':
            idx.append(i)
    n = len(idx)
    cnt = 0
    for mask in range(1 << n):
        test_arr = arr[:]
        for i in range(n):
            if mask & (1 << i):
                test_arr[idx[i]] = '#'
            else:
                test_arr[idx[i]] = '.'
        if get_groups(test_arr) == groups:
            cnt += 1
    total += cnt

print(total)
