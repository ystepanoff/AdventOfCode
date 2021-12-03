from collections import defaultdict
import sys

a = []
for line in sys.stdin:
    line = line.strip()
    a.append(line)

cnt = defaultdict(defaultdict)
for i in range(len(a)):
    for j in range(len(a[i])):
        if a[i][j] == '1':
            if 1 not in cnt[j]:
                cnt[j][1] = 0
            cnt[j][1] += 1
        else:
            if 0 not in cnt[j]:
                cnt[j][0] = 0
            cnt[j][0] += 1

n = len(a[0])

gamma, epsilon = 0, 0
for i in cnt.keys():
    if cnt[i][1] > cnt[i][0]:
        gamma = gamma | (1 << (n - i - 1))
    else:
        epsilon = epsilon | (1 << (n - i - 1))

print(gamma * epsilon)
