import sys
import re

R = 12
G = 13
B = 14

total = 0
for line in sys.stdin:
    line = line.rstrip()
    game = int(re.search('(?<=Game\s)\d+', line).group(0))
    rest = re.split('(?<=Game\s)\d+:\s', line)[-1]
    ok = True
    for group in rest.split('; '):
        for balls in re.split(', ', group):
            n, c = re.split(' ', balls)
            if (
                (c == 'red' and int(n) > R) or
                (c == 'green' and int(n) > G) or
                (c == 'blue' and int(n) > B)
            ):
                ok = False
    if ok:
        total += game
print(total)
