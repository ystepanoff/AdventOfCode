from decimal import *


def f(theta, steps=25):
    a, b = int(theta), theta
    r = str(a) + '.'
    for i in range(2, steps):
        b = int(b) * (b - int(b) + 1)
        a = int(b)
        r += str(a)
    return Decimal(r)


a = Decimal('2.95693889137798')
for i in range(1000):
    a = f(a)
print("{:.24f}".format(a))
