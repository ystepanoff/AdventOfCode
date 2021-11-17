n = int(input())
a = [input() for i in range(n)]
c = input()[0]
for s in [x for x in a if x[0] == c]:
    print(s)
