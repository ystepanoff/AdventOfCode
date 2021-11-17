n = int(input())
s = 0
for i in range(n + 1):
    s += (i + n) * (n - i + 1) // 2
    s += i * (n - i + 1)
print(s)
