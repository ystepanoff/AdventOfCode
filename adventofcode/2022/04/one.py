total = 0
for line in open('input'):
    one, two = line.strip().split(',')
    a, b = map(int, one.split('-'))
    x, y = map(int, two.split('-'))
    total += int((a <= x and y <= b) or (x <= a and b <= y))
print(total)
