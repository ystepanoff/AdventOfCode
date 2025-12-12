total = 0
for rng in input().split(','):
    l, r = map(int, rng.split('-'))
    for i in range(l, r + 1):
        s = str(i)
        m = len(s) >> 1
        if len(s) % 2 == 0 and s[m:] == s[:m]:
            total += i
print(total)

