from collections import defaultdict

cnt = defaultdict(int)
n = int(input())
for i in range(n):
    s = input()
    cnt[s] += 1
best = 0
r = s
for s in cnt.keys():
    if cnt[s] > best:
        best = cnt[s]
        r = s
print(r)
