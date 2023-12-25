import sys

import sympy as sp

lines = []

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    pos, vel = line.split(' @ ')
    pos = [int(x) for x in pos.split(', ')]
    vel = [int(x) for x in vel.split(', ')]
    lines.append((pos, vel))

# The easiest way out is to use SymPy to solve a system of equations

n = 10 # Possibly only first few lines are needed
vars = sp.symbols(f"x y z a b c {' '.join(f't_{i}' for i in range(n))}")
equations = []
for i, ((x, y, z), (a, b, c)) in enumerate(lines[:n]):
    equations.extend([
        sp.Eq(sp.S(f"{x} + {a} * t_{i}"), sp.S(f"x + a * t_{i}")),
        sp.Eq(sp.S(f"{y} + {b} * t_{i}"), sp.S(f"y + b * t_{i}")),
        sp.Eq(sp.S(f"{z} + {c} * t_{i}"), sp.S(f"z + c * t_{i}")),
    ])
solution = sp.solve(equations, vars)[0]
print(sum(solution[:3]))

