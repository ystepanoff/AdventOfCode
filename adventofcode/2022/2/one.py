total = 0
winning_pairs = {('C', 'X'), ('A', 'Y'), ('B', 'Z')}
for line in open('input'):
    a, b = map(str, line.split())
    total += ord(b) - ord('W')
    if ord(a) - ord('A') == ord(b) - ord('X'):
        total += 3
    elif (a, b) in winning_pairs:
        total += 6
print(total)
