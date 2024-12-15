import sys

G, W = set(), set()
d = {'v': 1, '^': -1, '<': -1j, '>': 1j}

lines = []
for line in sys.stdin:
    line = line.rstrip()
    if not line:
        break
    lines.append(line)

scaled_lines = []
for line in lines:
    new_line = []
    for ch in line:
        if ch == '#':
            new_line.append("##")
        elif ch == 'O':
            new_line.append("[]")
        elif ch == '.':
            new_line.append("..")
        elif ch == '@':
            new_line.append("@.")
        else:
            new_line.append(ch)
    scaled_lines.append("".join(new_line))

m, n = len(scaled_lines), len(scaled_lines[0])
r, box_map = None, {}
for i, line in enumerate(scaled_lines):
    for j, ch in enumerate(line):
        pos = i + j*1j
        if ch == '#':
            W.add(pos)
        elif ch == '@':
            r = pos
for i, line in enumerate(scaled_lines):
    for j in range(0, len(line), 2):
        pair = line[j:j+2]
        pos_left = i + j*1j
        pos_right = i + (j+1)*1j
        if pair == '[]':
            G.add(pos_left)
            G.add(pos_right)
            box = frozenset([pos_left, pos_right])
            box_map[pos_left] = box
            box_map[pos_right] = box
        j += 2

moves = ""
for line in sys.stdin:
    moves += line.rstrip()


def get_move_chain(box, dx):
    needed_boxes = {box}
    for c in box:
        new_pos = c + dx
        if new_pos in W:
            return None
        if new_pos in G and new_pos not in box:
            other_box = box_map[new_pos]
            if other_box not in needed_boxes:
                chain = get_move_chain(other_box, dx)
                if chain is None:
                    return None
                needed_boxes.update(chain)
    return frozenset(needed_boxes)


def move_box(box, dx):
    chain = get_move_chain(box, dx)
    if chain is None:
        return False
    for b in chain:
        for c in b:
            G.remove(c)
            del box_map[c]
    for b in chain:
        new_b = frozenset(c + dx for c in b)
        for c in new_b:
            G.add(c)
            box_map[c] = new_b
    return True


def move_robot(r, dx):
    next_cell = r + dx
    if next_cell in W:
        return r
    if next_cell in G:
        box = box_map[next_cell]
        if move_box(box, dx):
            if next_cell not in G and next_cell not in W:
                return r + dx
            else:
                return r
        else:
            return r
    else:
        return r + dx


for ch in moves:
    r = move_robot(r, d[ch])
final_boxes = set()
for c in G:
    final_boxes.add(box_map[c])
total = 0
for box in final_boxes:
    i, j = sorted([(int(pos.real), int(pos.imag)) for pos in box])[0]
    total += 100 * i + j
print(total)
