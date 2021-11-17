n = int(input())
a = [int(input()) for i in range(n)]
if a.count(3) > 0:
    print("None")
elif a.count(5) == n:
    print("Named")
elif sum(a) / n >= 4.5:
    print("High")
else:
    print("Common")
