A, B, C = (int(input().split()[-1]) for _ in range(3))
input()
p = [int(x) for x in input().split()[-1].split(',')]
out = []
i = 0
while i < len(p):
    combo = "0123ABC-"[p[i+1]]
    combo = int(combo) if combo.isdigit() else globals()[combo]
    match p[i]:
        case 0: A >>= combo
        case 1: B ^= p[i+1]
        case 2: B = combo & 7
        case 3: i = p[i+1] - 2 if A else i
        case 4: B ^= C
        case 5: out.append(combo & 7)
        case 6: B = A >> combo
        case 7: C = A >> combo
    i += 2
print(*out, sep=',')

