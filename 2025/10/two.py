import sys
import re

import numpy as np
from scipy.optimize import linprog


total = 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    target = tuple(map(int, re.search(r'\{([^}]+)\}', line).group(1).split(',')))
    btns = [tuple(int(i) for i in m.group(1).split(',')) for m in re.finditer(r'\(([^)]+)\)', line)]

    # Minimise sum(x_i), x_i >= 0, x_i integer
    # Subject to: for each counter j, sum(x_i for buttons i that affect j) = target[j]
    c = np.ones(len(btns))
    A = np.zeros((len(target), len(btns)))
    for i, b in enumerate(btns):
        for j in b:
            A[j, i] = 1
    b = np.array(target)
    total += int(linprog(c, A_eq=A, b_eq=b, integrality=True).fun)
print(total)
