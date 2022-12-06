marker = ''
for i, c in enumerate(open('input').read()):
    if len(marker) == 14:
        marker = marker[1:]
    marker += c
    if len(set(marker)) == 14:
        print(i + 1)
        break
