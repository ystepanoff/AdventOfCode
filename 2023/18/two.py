import sys

def parse_hex(s):
    s = s[2:-1]
    s, d = int(s[:-1], 16), int(s[-1])
    return s, d


dirs = {
    3: (-1, 0),
    1: (1, 0),
    0: (0, 1),
    2: (0, -1),
}

curr = (0, 0)
path = [curr]
last_d = None

for line in sys.stdin:
    line = line.rstrip()
    _, _, hex = line.split()
    s, d = parse_hex(hex)
    print(s, d)
    curr = (curr[0] + dirs[d][0] * s, curr[1] + dirs[d][1] * s)
    if d != last_d:
        path.append(curr)
    last_d = d

length = 1
sum1, sum2 = 0, 0
for i in range(1, len(path)):
    x1, y1 = path[i - 1]
    x2, y2 = path[i]
    length += abs(x1 - x2) + abs(y1 - y2)
    sum1 += x1 * y2
    sum2 += x2 * y1
print(int(length / 2 + 1 + abs(sum1 - sum2) / 2))
