import sys
import re


text = ''
for line in sys.stdin:
    text += line.strip()


text = re.sub(r'\(\*(.*?)\*\)', '', text)
balance = 0
yes = not '(*' in text
ops = '=+-*/0123456789)('
for c in text:
    if c == '(':
        balance += 1
    elif c == ')':
        balance -= 1
    if balance < 0:
        yes = False
        break
    if balance > 0 and not c in ops:
        yes = False
        break
yes = yes and balance == 0
if yes:
    print('YES')
else:
    print('NO')
