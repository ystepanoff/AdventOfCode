max_so_far = 0
curr = 0
with open('input') as file:
    for line in file:
        if line.strip() == '':
            max_so_far = max(curr, max_so_far)
            curr = 0
        else:
            curr += int(line)
print(max_so_far)
