marker = ''
for i, c in enumerate(open('input').read()):
    if len(marker) == 4:
        marker = marker[1:]
    marker += c
    if len(set(marker)) == 4:
        print(i + 1)`
        break
