total = 0
for rng in input().split(','):
    l, r = map(int, rng.split('-'))
    for i in range(l, r + 1):
        s = str(i)
        if s in (s + s)[1:-1]:
            total += i
print(total)

