from collections import defaultdict
cnt = defaultdict(int)
for x in list(map(int, input().split(','))):
    cnt[x] += 1
for i in range(256):
    new_cnt = defaultdict(int)
    for x, c in cnt.items():
        if x == 0:
            new_cnt[6] += c
            new_cnt[8] += c
        else:
            new_cnt[x - 1] += c
    cnt = new_cnt
print(sum(cnt.values()))
