import sys

for line in sys.stdin:
    a, id_ = [], 0
    pos = {}
    for i, c in enumerate(line.rstrip()):
        ext = [-1] * int(c)
        if i % 2 == 0:
            ext = [id_] * int(c)
            pos[id_] = (len(a), int(c))
            id_ += 1
        a.extend(ext)

    empty = []
    start, length = None, 0
    for i, x in enumerate(a):
        if x == -1:
            if start is None:
                start = i
            length += 1
        else:
            if start is not None:
                empty.append((start, length))
                start, length = None, 0
    if start is not None:
        empty.append((start, length))

    for id_ in range(id_ - 1, -1, -1):
        start, length = pos[id_]
        for i, (free_start, free_length) in enumerate(empty):
            if free_length >= length and free_start < start:
                for j in range(length):
                    a[start + j] = -1
                    a[free_start + j] = id_

                new_spans = []
                if free_start > start:
                    new_spans.append((free_start, free_start - start))
                if free_start + length < free_start + free_length:
                    new_spans.append((free_start + length, free_length - length))
                empty[i:i + 1] = new_spans
                break

    print(sum(i * x for i, x in enumerate(a) if x != -1))
