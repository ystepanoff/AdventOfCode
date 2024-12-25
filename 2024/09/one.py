from heapq import heapify, heappush, heappop
import sys

for line in sys.stdin:
    a, id_ = [], 0
    for i, c in enumerate(line.rstrip()):
        ext = [-1] * int(c)
        if i % 2 == 0:
            ext = [id_] * int(c)
            id_ += 1
        a.extend(ext)
    empty = []
    heapify(empty)
    for i, x in enumerate(a):
        if x == -1:
            heappush(empty, i)
    for i in range(len(a) - 1, len(empty), -1):
        if a[i] != -1:
            e = heappop(empty)
            a[e], a[i] = a[i], a[e]
            heappush(empty, i)
        if empty[0] >= i:
            break
    print(sum(i * x for i, x in enumerate(a) if x != -1))
