from collections import defaultdict
import sys
total = defaultdict(int)
for line in sys.stdin:
    line = line.rstrip()
    info, line = line.split(': ')
    n = int(info.split()[-1])
    total[n] += 1
    win, card = map(lambda s: set(int(x) for x in s.split()), line.split(' | '))
    for i in range(sum(1 for x in card if x in win)):
        total[n + i + 1] += total[n]
print(sum(total.values()))
