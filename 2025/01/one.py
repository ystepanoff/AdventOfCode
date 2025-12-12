import sys

curr, total = 50, 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    dir, dst = line[0], int(line[1:])
    if dir == 'L':
        curr = (curr - dst) % 100
    else:
        curr = (curr + dst) % 100
    total += curr == 0
print(total)

