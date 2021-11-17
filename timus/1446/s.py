from collections import defaultdict
n = int(input())
d = defaultdict(list)
for i in range(n):
    name = input().strip()
    fac = input().strip()
    d[fac].append(name)
fac = ["Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"]
for f in fac:
    print("{}:".format(f))
    for x in d[f]:
        print(x)
    print()
