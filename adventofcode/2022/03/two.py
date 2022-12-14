total = 0
lst = []
for line in open('input'):
    lst.append(set(line.strip()))
    if len(lst) == 3:
        c, = set.intersection(*lst)
        if c.islower():
            total += ord(c) - ord('a') + 1
        else:
            total += ord(c) - ord('A') + 27
        lst = []
print(total)
