from collections import defaultdict
stacks_input, stacks_input_mode = [], True
cmd_input = []
for line in open('input'):
    if line.strip() == '':
        stacks_input_mode = False
        continue
    if stacks_input_mode:
        stacks_input.append(line)
    else:
        cmd_input.append(line)
stacks = defaultdict(list)
for i, c in enumerate(stacks_input[-1]):
    if c not in ' \n':
        for line in reversed(stacks_input[:-1]):
            if len(line) > i and line[i].isalpha():
                stacks[int(c)].append(line[i])
for cmd in cmd_input:
    _, n, _, a, _, b = cmd.split()
    n, a, b = int(n), int(a), int(b)
    for i in range(n):
        stacks[b].append(stacks[a].pop())
for i in sorted(stacks.keys()):
    print(stacks[i][-1], end='')
print()
