total = 0
for line in open('input'):
    mid = len(line) >> 1
    c, = set(line[:mid]).intersection(set(line[mid:]))
    if c.islower():
        total += ord(c) - ord('a') + 1
    else:
        total += ord(c) - ord('A') + 27
print(total)
