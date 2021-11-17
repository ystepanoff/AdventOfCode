n, m = map(int, input().split())
a = [0] * n
for i in range(n):
    a[i] = int(input())
c = 0
for i in range(m):
    c = (c + 1) % n
print("".join([str(a[i % n]) for i in range(c, c + 10)]))
