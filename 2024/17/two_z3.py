A, B, C = (int(input().split()[-1]) for _ in range(3))
input()
p = [int(x) for x in input().split()[-1].split(',')]

# program: 2,4, 1,1, 7,5, 0,3, 1,4, 4,0, 5,5, 3,0
# B = A % 8
# B = B ^ 1
# C = A >> B
# A = A >> 3
# B = B ^ 4
# B = B ^ C
# out.append(B % 8)
# start over if A is not 0

# quick and cheeky z3 solution
from z3 import Optimize, BitVec
o = Optimize()
a = BitVec('A', 64)
A = a
for x in p:
    B = A % 8
    B = B ^ 1
    C = A >> B
    A = A >> 3
    B = B ^ 4
    B = B ^ C
    o.add((B % 8) == x)
o.add(A == 0)
o.minimize(a)
if str(o.check()) == "sat":
    print(o.model())

