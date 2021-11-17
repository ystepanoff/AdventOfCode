n = int(input())
total = 2
for i in range(n):
    line = input().strip()
    total += 1
    if line.endswith('+one'):
        total += 1
if total == 13:
    total = 14
print(total * 100)
