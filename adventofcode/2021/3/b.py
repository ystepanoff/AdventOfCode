import sys

a = []
for line in sys.stdin:
    line = line.strip()
    a.append(line)

tmp = a[:]

for i in range(len(a[0])):
    if len(a) == 1:
        break
    o, z = 0, 0
    for j in range(len(a)):
        if a[j][i] == '1':
            o += 1
        else:
            z += 1
    b = []
    if o >= z:
        for j in range(len(a)):
            if a[j][i] == '1':
                b.append(a[j])
    else:
        for j in range(len(a)):
            if a[j][i] == '0':
                b.append(a[j])
    a = b[:]

O = a[0]

a = tmp[:]
for i in range(len(a[0])):
    if len(a) == 1:
        break
    o, z = 0, 0
    for j in range(len(a)):
        if a[j][i] == '1':
            o += 1
        else:
            z += 1
    b = []
    if z <= o:
        for j in range(len(a)):
            if a[j][i] == '0':
                b.append(a[j])
    else:
        for j in range(len(a)):
            if a[j][i] == '1':
                b.append(a[j])
    a = b[:]

CO2 = a[0]

x, y = 0, 0
for i in range(len(O)):
    if O[i] == '1':
        x = x | (1 << (len(O) - i - 1))
    if CO2[i] == '1':
        y = y | (1 << (len(O) - i - 1))

print(x * y)
