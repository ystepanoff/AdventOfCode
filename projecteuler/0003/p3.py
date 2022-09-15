N = 600851475143
c = 2
best = 0
while c * c <= N:
    if N % c == 0:
        best = max(best, c)
        while N % c == 0:
            N = N // c
    c += 1
if N > 1:
    best = max(best, N)
print(N)
