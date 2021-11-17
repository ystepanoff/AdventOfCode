n = int(input())
best, curr = 0, 0
for i in range(n):
    a = int(input())
    curr = max(0, curr + a)
    best = max(best, curr)
print(best)
