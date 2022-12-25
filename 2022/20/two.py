from collections import deque
a = [int(line.rstrip()) * 811589153 for line in open('input') if line.rstrip()]
a = deque(list(enumerate(a)))
for _ in range(10):
    for i in range(len(a)):
        while a[0][0] != i:
            a.append(a.popleft())
        v = a.popleft()
        for _ in range(v[1] % len(a)):
            a.append(a.popleft())
        a.append(v)
a = [y for _, y in a]
idx = a.index(0)
print(a[(idx + 1000) % len(a)] + a[(idx + 2000) %
      len(a)] + a[(idx + 3000) % len(a)])
