n, m = map(int, input().split())
n *= 3
s = 0
free = False
for i in range(m):
    x = int(input())
    s += x
    if s > n:
        free = True
        print(f"Free after {i + 1} times.")
        break
if not free:
    print("Team.GOV!")
