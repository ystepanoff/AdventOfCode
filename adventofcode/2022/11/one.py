monkeys = {}
for line in open('input'):
    line = line.strip()
    if line.startswith('Monkey'):
        curr_monkey = int(line.rstrip(':').split()[-1])
    elif line.startswith('Starting items'):
        line = line.replace('Starting items: ', '')
        monkeys[curr_monkey] = {
            'items': list(map(int, line.split(', '))),
            'count': 0,
        }
    elif line.startswith('Operation'):
        line = line.replace('Operation: new = ', '')
        monkeys[curr_monkey]['op'] = line
    elif line.startswith('Test'):
        monkeys[curr_monkey]['test'] = int(line.split()[-1])
    elif line.startswith('If true'):
        monkeys[curr_monkey]['test_true'] = int(line.split()[-1])
    elif line.startswith('If false'):
        monkeys[curr_monkey]['test_false'] = int(line.split()[-1])

def round(monkeys):
    for monkey in sorted(monkeys.keys()):
        for item in monkeys[monkey]['items']:
            worry = eval(monkeys[monkey]['op'].replace('old', str(item)))
            worry //= 3
            if worry % monkeys[monkey]['test'] == 0:
                monkeys[monkeys[monkey]['test_true']]['items'].append(worry)
            else:
                monkeys[monkeys[monkey]['test_false']]['items'].append(worry)
            monkeys[monkey]['count'] += 1
        monkeys[monkey]['items'] = []
    return monkeys

for i in range(20):
    monkeys = round(monkeys)
counts = sorted(monkeys[monkey]['count'] for monkey in monkeys)
print(counts[-1] * counts[-2])
