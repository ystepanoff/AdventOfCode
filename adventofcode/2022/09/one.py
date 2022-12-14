head, tail = [0, 0], [0, 0]
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
dirs = "URDL"
locs = set()
for line in open('input'):
    d, n = line.strip().split()
    d, n = dirs.index(d), int(n)
    for i in range(n):
        head[0] += dx[d]
        head[1] += dy[d]
        if abs(head[0] - tail[0]) > 1 or abs(head[1] - tail[1]) > 1:
            if head[0] - tail[0] == 1:
                tail[0] += 1
            elif tail[0] - head[0] == 1:
                tail[0] -= 1
            elif head[1] - tail[1] == 1:
                tail[1] += 1
            elif tail[1] - head[1] == 1:
                tail[1] -= 1
            tail[0] += dx[d]
            tail[1] += dy[d]
        locs.add(tuple(tail))
print(len(locs))
