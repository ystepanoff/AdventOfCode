alpha = 1504170715041707
beta = 4503599627370517

coins = [
    (1504170715041707, 1),
    (8912517754604, 3),
    (2044785486369, 506),
    (1311409677241, 2527),
    (578033868113, 4548),
    (422691927098, 11117),
    (267349986083, 17686),
    (112008045068, 24255),
    (68674149121, 55079),
    (25340253174, 85903),
    (7346610401, 202630),
    (4046188430, 724617),
    (745766459, 1246604),
    (428410324, 6755007),
    (111054189, 12263410),
    (15806432, 42298633),
    (15397267, 326125654),
    (14988102, 609952675)
]


def gcdex(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = gcdex(b, a % b)
    return g, y, x - (a // b) * y


g, x0, y0 = gcdex(alpha, beta)
cand = []
for n in range(coins[-1][0] + 1, 0, -1):
    x = (beta + x0 * n) % beta
    cand.append((n, x))
cand = sorted(cand, key=lambda t: t[1])
for n, x in cand:
    if n < coins[-1][0]:
        coins.append((n, x))
print(sum([c[0] for c in coins]))