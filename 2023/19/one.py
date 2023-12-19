import sys

flows = {}
parts = []

state = False
for line in sys.stdin:
    line = line.strip()
    if not line:
        state = True
        continue
    if state:
        line = line[1:-1]
        part = {}
        for rating in line.split(','):
            r, v = rating.split('=')
            part[r] = int(v)
        parts.append(part)
    else:
        flow, rules = line.split('{')
        rules = rules[:-1].split(',')
        flows[flow] = []
        for rule in rules:
            if ':' in rule:
                r, f = rule.split(':')
                if '<' in r:
                    x, y = r.split('<')
                    flows[flow].append((x, '<', int(y), f))
                if '>' in r:
                    x, y = r.split('>')
                    flows[flow].append((x, '>', int(y), f))
            else:
                flows[flow].append(rule)

total = 0
for part in parts:
    flow = 'in'
    while flow not in ['A', 'R']:
        for rule in flows[flow]:
            if isinstance(rule, tuple):
                x, op, y, f = rule
                if op == '<':
                    if part[x] < y:
                        flow = f
                        break
                elif op == '>':
                    if part[x] > y:
                        flow = f
                        break
            else:
                flow = rule
                break
    if flow == 'A':
        total += sum(part.values())
print(total)
