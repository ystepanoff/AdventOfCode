n = int(input())
a = [int(elem) for elem in input().split()]
d = {}
for i, num in enumerate(a):
    if num in d:
        d[num] += 1
    else:
        d[num] = num + 1
    if d[num] == n:
        break
print(n, i)
print(n - i - 1)
