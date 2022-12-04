total = 0
for line in open('input'):
    one, two = line.strip().split(',')
    a, b = map(int, one.split('-'))
    x, y = map(int, two.split('-'))
    total += int((a <= x and x <= b) or \
                 (a <= y and y <= b) or \
                 (x <= a and a <= y) or \
                 (x <= a and a <= y))
print(total)
