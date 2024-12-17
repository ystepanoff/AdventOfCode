A, B, C = (int(input().split()[-1]) for _ in range(3))
input()
p = [int(x) for x in input().split()[-1].split(',')]


def run(A, B, C, p):
    out = []
    i = 0
    while i < len(p):
        combo = "0123ABC-"[p[i + 1]]
        combo = int(combo) if combo.isdigit() else locals()[combo]
        match p[i]:
            case 0: A >>= combo
            case 1: B ^= p[i + 1]
            case 2: B = combo & 7
            case 3: i = p[i + 1] - 2 if A else i
            case 4: B ^= C
            case 5: out.append(combo & 7)
            case 6: B = A >> combo
            case 7: C = A >> combo
        i += 2
    return out


def find(idx, a):
    return (print(a) or True) if idx < 0 else \
        any(run((a << 3) | d, B, C, p)[0] == p[idx] and find(idx - 1, (a << 3) | d) for d in range(8))


find(len(p) - 1, 0)
