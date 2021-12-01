import sys

a, lst = [], []
for line in sys.stdin:
    line = line.strip()
    a.append(int(line))
for i in range(1, len(a) - 1):
    lst.append(a[i - 1] + a[i] + a[i + 1])
total = 0
for i in range(1, len(lst)):
    if lst[i] > lst[i - 1]:
        total += 1
print(total)
