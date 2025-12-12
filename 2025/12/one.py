import sys

def normalise(shape):
    shape = list(shape)
    mx = min(x for x, _ in shape)
    my = min(y for _, y in shape)
    return frozenset((x - mx, y - my) for x, y in shape)

def get_tiles(shape):
    tiles = set()
    shape = normalise(shape)
    for _ in range(4):
        tiles.add(shape)
        tiles.add(normalise(list((x, -y) for x, y in shape)))
        shape = normalise(list((y, -x) for x, y in shape))
    return list(tiles)

def get_bb(shape):
    mx = max(x for x, _ in shape)
    my = max(y for _, y in shape)
    return mx + 1, my + 1

def can(curr, shape, r, c, w, h):
    for x, y in shape:
        new_x, new_y = r + x, c + y
        if new_x >= h or new_y >= w or (new_x, new_y) in curr:
            return False
    return True

def place(curr, shape, r, c):
    cells = set()
    for x, y in shape:
        cell = (r + x, c + y)
        curr.add(cell)
        cells.add(cell)
    return cells

def solve(w, h, pr, all_tiles):
    def rec(curr, idx):
        if idx == len(pr):
            return True
        tiles = all_tiles[pr[idx]]
        for tile in tiles:
            th, tw = get_bb(tile)
            for r in range(h - th + 1):
                for c in range(w - tw + 1):
                    if can(curr, tile, r, c, w, h):
                        cells = place(curr, tile, r, c)
                        if rec(curr, idx + 1):
                            return True
                        curr -= cells
        return False

    return rec(set(), 0)

shapes = {}
for inp in sys.stdin.read().strip().split('\n\n'):
    lines = inp.strip().split('\n')
    if lines[0][-1] == ':':
        idx = int(lines[0][:-1])
        coords = set()
        for i, line in enumerate(lines[1:]):
            for j, ch in enumerate(line):
                if ch == '#':
                    coords.add((i, j))
        shapes[idx] = frozenset(coords)
    else:
        all_tiles = {}
        for idx, shape in shapes.items():
            all_tiles[idx] = get_tiles(shape)
        total = 0
        for line in lines:
            dim, cnt = line.split(': ')
            w, h = map(int, dim.split('x'))
            cnt = list(map(int, cnt.split()))
            need = sum(cnt[i] * len(shapes[i]) for i in range(len(cnt)))
            if need > w * h:
                continue
            pr = []
            for i, c in enumerate(cnt):
                pr.extend([i] * c)
            #pr.sort(key=lambda i: -len(next(iter(all_tiles[i]))))
            if solve(w, h, pr, all_tiles):
                total += 1
        print(total)

