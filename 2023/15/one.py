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
print(sum(hash(s) for s in inp.split(',')))
