n = int(input())
a = sorted([int(input()) for i in range(n)])
found = False
for i in range(n - 2):
    x, y, z = a[i], a[i + 1], a[i + 2]
    if x + y > z and x + z > y and y + z > x:
        print(x, y, z)
        found = True
        break
if not found:
    print("0 0 0")
