import sys

flows = {}

state = False
for line in sys.stdin:
    line = line.strip()
    if not line:
        break

    flow, rules = line.split('{')
    rules = rules[:-1].split(',')
    flows[flow] = [rule for rule in rules]

all_rules = []

def dfs(current, rules):
    if current == 'A':
        all_rules.append(rules)
    elif current != 'R':
        r = []
        for rule in flows[current][:-1]:
            if rule not in 'AR':
                next_flow = rule.split(':')[1]
                dfs(next_flow, rules + r + [rule.split(':')[0]])
                if rule[1] == '<':
                    r.append(rule.split(':')[0].split('<')[0] + '>=' + rule.split(':')[0].split('<')[1])
                elif rule[1] == '>':
                    r.append(rule.split(':')[0].split('>')[0] + '<=' + rule.split(':')[0].split('>')[1])
        else:
            next_flow = flows[current][-1]
            dfs(next_flow, rules + r)


dfs('in', [])
total = 0
for rules in all_rules:
    maxs = {x: 4001 for x in 'xmas'}
    mins = {x: 0 for x in 'xmas'}
    for rule in rules:
        if rule[1] == '<':
            maxs[rule[0]] = min(maxs[rule[0]], int(rule[2:])) if rule[2] != '=' else min(maxs[rule[0]], int(rule[3:]) + 1)
        elif rule[1] == '>':
            mins[rule[0]] = max(mins[rule[0]], int(rule[2:])) if rule[2] != '=' else max(mins[rule[0]], int(rule[3:]) - 1)
    r = 1
    for key in maxs:
        r *= (maxs[key] - mins[key] - 1)
    total += r
print(total)
