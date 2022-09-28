CACHE = {}

def count(n, pos, l, r, cnt):
    if n == 0:
        return 1 if all([c == cnt[0] for c in cnt]) and \
            l % 5 == 0 and r % 5 == 0 else 0
    if (pos, tuple(cnt)) not in CACHE:
        cnt[(pos + 1) % 5] += 1
        cl = count(n - 1, (pos + 1) % 5, l + 1, r, cnt)
        cnt[(pos + 1) % 5] -= 1
        cnt[(pos + 4) % 5] += 1
        cr = count(n - 1, (pos + 4) % 5, l, r + 1, cnt)
        cnt[(pos + 4) % 5] -= 1
        CACHE[pos, tuple(cnt)] = cl + cr
    return CACHE[pos, tuple(cnt)]

print(count(70, 0, 0, 0, [0] * 5))
