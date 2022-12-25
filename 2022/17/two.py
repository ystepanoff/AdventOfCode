def new_rock(n, y):
    pieces = [
        {(2, y), (3, y), (4, y), (5, y)},
        {(3, y), (2, y + 1), (3, y + 1), (4, y + 1), (3, y + 2)},
        {(2, y), (3, y), (4, y), (4, y + 1), (4, y + 2)},
        {(2, y), (2, y + 1), (2, y + 2), (2, y + 3)},
        {(2, y), (3, y), (2, y + 1), (3, y + 1)},
    ]
    return pieces[n % 5]

def can_left(piece):
    if not all(x > 0 for x, _ in piece):
        return False
    piece_next = {(x - 1, y) for x, y in piece}
    return len(TOWER.intersection(piece_next)) == 0

def can_right(piece):
    if not all(x < 6 for x, _ in piece):
        return False
    piece_next = {(x + 1, y) for x, y in piece}
    return len(TOWER.intersection(piece_next)) == 0

TOWER = set()

def can_down(piece):
    if not all(y > 0 for _, y in piece):
        return False
    piece_next = {(x, y - 1) for x, y in piece}
    return len(TOWER.intersection(piece_next)) == 0

def height():
    if not TOWER:
        return 0
    return max(y for _, y in TOWER)

def state():
    st = ''
    y = height()
    for i in range(100):
        for x in range(7):
            if (x, y - i) in TOWER:
                st += '1'
            else:
                st += '0'
    return st

moves, move = open('input').read().strip(), 0
r, L = 0, 10 ** 12
cache = {}
total = 0
while r < L:
    if not TOWER:
        piece = new_rock(r, 3)
    else:
        piece = new_rock(r, height() + 4)
    while True:
        if moves[move] == '>' and can_right(piece):
            piece = {(x + 1, y) for x, y in piece}
        elif moves[move] == '<' and can_left(piece):
            piece = {(x - 1, y) for x, y in piece}
        move = (move + 1) % len(moves)
        if  not can_down(piece):
            TOWER = TOWER.union(piece)
            break
        else:
            piece = {(x, y - 1) for x, y in piece}
    if r > 2000:
        key = (r % 5, move, state())
        if key in cache:
            old_r, old_y = cache[key]
            dr, dy = r - old_r, height() - old_y
            rocks = (L - r) // dr
            total += rocks * dy
            r += rocks * dr
        cache[key] = (r, height())
    r += 1
print(height() + total + 1)
