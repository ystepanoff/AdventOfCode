import sys


def hash(s):
    h = 0
    for c in s:
        h = ((h + ord(c)) * 17)  % 256
    return h


inp = ''
for line in sys.stdin:
    line = line.rstrip()
    inp += line


boxes = {i: [] for i in range(256)}
    
for s in inp.split(','):
    if '=' in s:
        l, f = s.split('=')
        f = int(f)
        h = hash(l)
        found = False
        for i, (bl, bf) in enumerate(boxes[h]):
            if bl == l:
                found = True
                boxes[h][i] = (l, f)
        if not found:
            boxes[h].append((l, f)) 
    elif '-' in s:
        l = s[:-1]
        h = hash(l)
        for i, (bl, _) in enumerate(boxes[h]):
            if bl == l:
                boxes[h].pop(i)

total = 0
for i in range(256):
    for j, (l, f) in enumerate(boxes[i]):
        total += (i + 1) * (j + 1) * f
print(total)
