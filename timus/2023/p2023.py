boxes = {
    "A": 0,
    "P": 0,
    "O": 0,
    "R": 0,
    "B": 1,
    "M": 1,
    "S": 1,
    "D": 2,
    "G": 2,
    "J": 2,
    "K": 2,
    "T": 2,
    "W": 2
}

n = int(input())
c, t = 0, 0
for i in range(n):
    s = input()
    t += abs(boxes[s[0]] - c)
    c = boxes[s[0]]
print(t)
