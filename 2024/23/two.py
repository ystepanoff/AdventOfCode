import sys
from collections import defaultdict


def bk(curr, cand, out):
    if not cand and not out:
        yield curr
    while cand:
        v = cand.pop()
        yield from bk(curr | {v}, cand & G[v], out & G[v])
        out.add(v)


G = defaultdict(set)
for line in sys.stdin:
    u, v = line.rstrip().split('-')
    G[u].add(v)
    G[v].add(u)


print(",".join(sorted(max([c for c in bk(set(), set(G), set())], key=lambda s: len(s)))))
