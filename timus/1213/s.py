import sys

rooms = set()

for line in sys.stdin:
    if not '-' in line:
        continue
    if line == '#':
        break
    f, t = line.strip().split('-')
    rooms.add(f)
    rooms.add(t)

print(max(0, len(rooms) - 1))
