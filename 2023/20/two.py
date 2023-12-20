import math
import sys

flip_flops = {}
conjunctions = {}
nodes = {}

for line in sys.stdin:
    line = line.rstrip().split(' -> ')
    inp, outs = line[0], list(line[1].split(', '))
    
    if inp[0] == '%':
        flip_flops[inp[1:]] = False
        nodes[inp[1:]] = outs
    elif inp[0] == '&':
        conjunctions[inp[1:]] = {}
        nodes[inp[1:]] = outs
    else:
        nodes[inp] = outs

    for c_out in conjunctions.keys():
        for inp, outs in nodes.items():
            if c_out in outs:
                conjunctions[c_out][inp] = False

dr_inputs = {}
i = 0
while True:
    i += 1
    q = [('button', 'broadcaster', False)]
    for inp, out, pulse in q:
        if out == 'dr':
            if pulse:
                if inp not in dr_inputs:
                    dr_inputs[inp] = i
                    print(dr_inputs)
        if out == 'button':
            q.append(('button', 'broadcaster', False))
        elif out == 'broadcaster':
            for node in nodes[out]:
                q.append((out, node, pulse))
        elif out in flip_flops:
            if pulse:
                continue
            flip_flops[out] = not flip_flops[out]
            for node in nodes[out]:
                q.append((out, node, flip_flops[out]))            
        elif out in conjunctions:
            assert inp in conjunctions[out]
            conjunctions[out][inp] = pulse
            for node in nodes[out]:
                q.append((out, node, not all(conjunctions[out].values())))
    if len(dr_inputs) == 4: # determined that by looking at the input
        break

lcm = 1
for x in dr_inputs.values():
    lcm = (lcm * x) // math.gcd(lcm, x)
print(lcm)
