import sys
import re

EPS = 1e-9

def simplex(c, A, b):
    m, n = len(b), len(c)
    A = [row[:] for row in A]
    b = b[:]
    for i in range(m):
        if b[i] < 0:
            A[i] = [-x for x in A[i]]
            b[i] = -b[i]
    tableau = [A[i] + [0.0]*m + [b[i]] for i in range(m)]
    for i in range(m):
        tableau[i][n + i] = 1.0
    obj = [0.0]*n + [1.0]*m + [0.0]
    for i in range(m):
        for j in range(len(obj)):
            obj[j] -= tableau[i][j]
    tableau.append(obj)
    basic = list(range(n, n + m))

    def iterate(tableau, basic, cols):
        for _ in range(10000):
            entering = -1
            min_c = -EPS
            for j in range(cols):
                if tableau[-1][j] < min_c:
                    min_c = tableau[-1][j]
                    entering = j
            if entering == -1:
                return tableau, basic
            leaving = -1
            min_r = float('inf')
            for i in range(len(tableau) - 1):
                if tableau[i][entering] > EPS:
                    r = tableau[i][-1] / tableau[i][entering]
                    if r < min_r - EPS:
                        min_r = r
                        leaving = i
            if leaving == -1:
                return None, basic
            pv = tableau[leaving][entering]
            tableau[leaving] = [x / pv for x in tableau[leaving]]
            for i in range(len(tableau)):
                if i != leaving and abs(tableau[i][entering]) > EPS:
                    f = tableau[i][entering]
                    tableau[i] = [tableau[i][j] - f * tableau[leaving][j] for j in range(len(tableau[i]))]
            basic[leaving] = entering
        return None, basic

    tableau, basic = iterate(tableau, basic, n + m)
    if tableau is None or abs(tableau[-1][-1]) > EPS:
        return None, None
    for i in range(m):
        if basic[i] >= n:
            for j in range(n):
                if abs(tableau[i][j]) > EPS:
                    pv = tableau[i][j]
                    tableau[i] = [x / pv for x in tableau[i]]
                    for k in range(len(tableau)):
                        if k != i and abs(tableau[k][j]) > EPS:
                            f = tableau[k][j]
                            tableau[k] = [tableau[k][l] - f * tableau[i][l] for l in range(len(tableau[k]))]
                    basic[i] = j
                    break
    tableau2 = [tableau[i][:n] + [tableau[i][-1]] for i in range(m)]
    obj2 = c[:] + [0.0]
    for i in range(m):
        if basic[i] < n and abs(obj2[basic[i]]) > EPS:
            f = obj2[basic[i]]
            for j in range(len(obj2)):
                obj2[j] -= f * (tableau2[i][j] if j < n else tableau2[i][-1] if j == n else 0)
    tableau2.append(obj2)
    tableau2, basic = iterate(tableau2, basic, n)
    if tableau2 is None:
        return None, None
    sol = [0.0] * n
    for i in range(m):
        if basic[i] < n:
            sol[basic[i]] = tableau2[i][-1]
    return -tableau2[-1][-1], sol

def solve_ilp(c, A, b):
    n = len(c)
    best = [float('inf'), None]

    def bounded_lp(lo, hi):
        m = len(b)
        ub_cnt = sum(1 for x in hi if x < float('inf'))
        b2 = [b[i] - sum(A[i][j] * lo[j] for j in range(n)) for i in range(m)]
        A2 = [A[i][:] + [0.0]*ub_cnt for i in range(m)]
        b2_full = b2[:]
        si = n
        for i in range(n):
            if hi[i] < float('inf'):
                row = [0.0] * (n + ub_cnt)
                row[i] = 1.0
                row[si] = 1.0
                A2.append(row)
                b2_full.append(hi[i] - lo[i])
                si += 1
        c2 = c[:] + [0.0]*ub_cnt
        obj, sol = simplex(c2, A2, b2_full)
        if obj is None:
            return None, None
        sol_orig = [sol[i] + lo[i] for i in range(n)]
        return sum(c[i] * sol_orig[i] for i in range(n)), sol_orig

    def branch(lo, hi):
        obj, sol = bounded_lp(lo, hi)
        if obj is None or obj >= best[0] - EPS:
            return
        frac_i = -1
        for i in range(n):
            f = sol[i] - int(sol[i] + EPS)
            if f < 0:
                f += 1
            if EPS < f < 1 - EPS:
                frac_i = i
                break
        if frac_i == -1:
            int_sol = [int(x + EPS) for x in sol]
            int_obj = sum(c[i] * int_sol[i] for i in range(n))
            if int_obj < best[0]:
                best[0] = int_obj
                best[1] = int_sol
            return
        v = int(sol[frac_i])
        hi2 = hi[:]
        hi2[frac_i] = float(v)
        if hi2[frac_i] >= lo[frac_i]:
            branch(lo, hi2)
        lo2 = lo[:]
        lo2[frac_i] = float(v + 1)
        if lo2[frac_i] <= hi[frac_i]:
            branch(lo2, hi)

    branch([0.0]*n, [float('inf')]*n)
    return int(round(best[0])) if best[1] else None

total = 0
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    target = tuple(map(int, re.search(r'\{([^}]+)\}', line).group(1).split(',')))
    btns = [tuple(int(i) for i in m.group(1).split(',')) for m in re.finditer(r'\(([^)]+)\)', line)]
    c = [1.0] * len(btns)
    A = [[0.0] * len(btns) for _ in range(len(target))]
    for i, b in enumerate(btns):
        for j in b:
            A[j][i] = 1.0
    b = [float(t) for t in target]
    total += solve_ilp(c, A, b)
print(total)
