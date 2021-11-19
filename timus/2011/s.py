n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 4
for x in a:
    cnt[x] += 1
k = 1
for i in range(1, n + 1):
    k *= i
for i in range(1, 4):
    for j in range(1, cnt[i] + 1):
        k //= j
if k >= 6:
    print("Yes")
else:
    print("No")
