import sys

x, y = 0, 0
for line in sys.stdin:
    cmd, val = line.strip().split()
    val = int(val)
    match cmd:
        case "forward":
            x += val
        case "down":
            y += val
        case "up":
            y -= val
print(x * y)
