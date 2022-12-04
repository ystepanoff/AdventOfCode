total = 0
to_win = {'A': 'Y', 'B': 'Z', 'C': 'X'}
to_lose = {'A': 'Z', 'B': 'X', 'C': 'Y'}
winning_pairs = {('C', 'X'), ('A', 'Y'), ('B', 'Z')}
for line in open('input'):
    a, x = map(str, line.split())
    if x == 'X':
        b = to_lose[a]
    elif x == 'Y':
        b = chr(ord(a) + ord('X') - ord('A'))
    elif x == 'Z':
        b = to_win[a]
    total += ord(b) - ord('W')
    if ord(a) - ord('A') == ord(b) - ord('X'):
        total += 3
    elif (a, b) in winning_pairs:
        total += 6
print(total)
