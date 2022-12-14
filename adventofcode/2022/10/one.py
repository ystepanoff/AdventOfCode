cycles = {20, 60, 100, 140, 180, 220}
x, c = 1, 1
total = 0
for line in open('input'):
    line = line.strip()
    if line.startswith('noop'):
        c += 1
        if c in cycles:
            total += c * x
    else:
        _, n = line.split()
        n = int(n)
        c += 1
        if c in cycles:
            total += c * x
        c += 1
        x += n
        if c in cycles:
            total += c * x
print(total)
