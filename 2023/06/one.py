import re
import sys

times, dists = sys.stdin.read().split('\n')[:2]
times = [int(x) for x in re.findall(r'\d+', times)]
dists = [int(x) for x in re.findall(r'\d+', dists)]

total = 1
for i in range(len(times)):
    cnt = 0
    for j in range(times[i] + 1):
        left = times[i] - j
        if left * j > dists[i]:
            cnt += 1
    if cnt > 0:
        total *= cnt
print(total)
