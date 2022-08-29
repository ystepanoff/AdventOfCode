T = int(input())
for t in range(T):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    result = 'YES'
    if n > 2 * k:
        result = 'NO'
    else:
        for x in a:
            if a.count(x) > 2:
                result = 'NO'
    print('Case #{}: {}'.format(t + 1, result))
