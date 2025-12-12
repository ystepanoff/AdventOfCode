import sys

r, total = [], 0

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    if '-' in line:
        r.append([int(x) for x in line.split('-')])

r.sort()
curr_a, curr_b = r[0]
for a, b in r[1:]:
    if a > curr_b:
        total += curr_b - curr_a + 1
        curr_a, curr_b = a, b
    else:
        curr_b = max(curr_b, b)
total += curr_b - curr_a + 1
print(total)
