calories = []
curr = 0
with open('input') as file:
    for line in file:
        if line.strip() == '':
            calories.append(curr)
            curr = 0
        else:
            curr += int(line)
calories.sort()
print(sum(calories[-3:]))
