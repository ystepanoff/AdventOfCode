import sys

x, y, z = 0, 0, 0
for line in sys.stdin:
    cmd, val = line.strip().split()
    val = int(val)
    match cmd:
        case "forward":
            x += val
            y += val * z
        case "down":
            z += val
        case "up":
            z -= val
print(x * y)
