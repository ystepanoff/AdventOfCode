import sys

lst = []
for line in sys.stdin:
    line = line.strip()
    lst.append(int(line))
total = 0
for i in range(1, len(lst)):
    if lst[i] > lst[i - 1]:
        total += 1
print(total)
