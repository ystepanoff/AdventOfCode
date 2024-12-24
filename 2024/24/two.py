import sys


r = {}
last, state = "z00", 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        state = 1
        continue
    if state:
        a, op, b, _, c = line.split()
        r[c] = (a, b, op)


SEEN = set()
ADDER = []


def process(w):
    if w in SEEN:
        return
    a, b, op = r[w]
    if a[0] not in "xy":
        process(a)
    if b[0] not in "xy":
        process(b)
    ADDER.append((a, b, op, w))
    SEEN.add(w)


adders = []
for i in range(1000):
    z = f"z{i:02}"
    if z not in r:
        break
    ADDER = []
    process(z)
    adders.append(ADDER)

bad = set()
for adder in adders[2:]:
    for a, b, op, c in adder:
        if c[0] == 'z' and op != "XOR" and c != last:
            bad.add(c)
        elif c[0] != 'z' and op == "XOR" and all(w[0] not in "xyz" for w in (a, b)):
            bad.add(c)
        elif op == "XOR" and any(c in [a_, b_] and op_ == "OR" for a_, b_, op_, c_ in adder):
            bad.add(c)
        elif op == "AND" and any(c in [a_, b_] and op_ != "OR" for a_, b_, op_, c_ in adder):
            bad.add(c)
print(",".join(sorted(bad)))
