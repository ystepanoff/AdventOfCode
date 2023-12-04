import sys
total = 0
for line in sys.stdin:
    line = line.rstrip()
    line = line.split(': ')[1]
    win, card = map(lambda s: set(int(x) for x in s.split()), line.split(' | '))
    c = sum(1 for x in card if x in win)
    total += 1 << (c - 1) if c > 0 else 0
print(total)
