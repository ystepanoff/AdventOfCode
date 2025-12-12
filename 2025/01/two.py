import sys

curr, total = 50, 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    dir, dst = line[0], int(line[1:])
    step = [-1, 1][dir != 'L']
    for _ in range(dst):
        curr = (curr + step) % 100
        if curr == 0:
            total += 1
print(total)

