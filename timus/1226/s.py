import sys

text = sys.stdin.read()
result = ''
w = ''
for c in text:
    if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'):
        w += c
    else:
        if w != '':
            result += w[::-1]
            w = ''
        result += c
if w != '':
    result += w[::-1]
print(result, end='')
