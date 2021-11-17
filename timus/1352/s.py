lst = [1, 2, 3, -1, -1, -1, -1, -1, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593]

mersenn = []
for i in range(1, 32):
    p = 2 ** i - 1 
    prime = True
    c = 2
    while c * c <= p:
        if p % c == 0:
            prime = False
            break
        c += 1
    if prime:
        mersenn.append(i)

t = int(input())
for i in range(t):
    n = int(input())
    if lst[n] == -1:
        print(mersenn[n])
    else:
        print(lst[n])
