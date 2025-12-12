import sys

r, total = [], 0

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    if '-' in line:
        r.append([int(x) for x in line.split('-')])
    else:
        for a, b in r:
            if a <= int(line) <= b:
                total += 1
                break
print(total)
