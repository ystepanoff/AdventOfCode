x, y = map(int, input().split())
if x < 0 or y < 0 or x % 2 == y % 2:
    print(x, y)
else:
    print(y, x)
