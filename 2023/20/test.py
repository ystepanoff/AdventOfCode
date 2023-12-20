def load_input_file(file_name):
    with open(file_name) as file:
        yield from (line.rstrip() for line in file)


def parse(task_input):
    for line in task_input:
        t = line.split(' -> ')

        yield t[0], tuple(t[1].split(', '))


def run(task_input):
    lines = list(parse(task_input))

    flip_flops = {}
    conjunctions = {}
    module = {}

    for name, where in lines:
        if name[0] == '%':
            flip_flops[name[1:]] = False
            module[name[1:]] = where
            continue

        if name[0] == '&':
            conjunctions[name[1:]] = {}
            module[name[1:]] = where
            continue

        module[name] = where


    for c in conjunctions.keys():
        for name, where in module.items():
            if c in where:
                conjunctions[c][name] = False


    a, b = 0, 0
    results = { 0: (0, 0)}

    for pressed_button in range(1000):
        events = [ ('broadcaster', False, 'button') ]

        while events:
            where, impulse, _from = events.pop(0)
            # print(where, impulse)

            if impulse:
                a += 1
            else:
                b += 1

            if where == 'button':
                events.append( ('broadcaster', False, where) )

            elif where == 'broadcaster':
                for w in module[where]:
                    events.append((w, impulse, where))
            elif where in flip_flops:
                if impulse:
                    continue
                else:
                    if not flip_flops[where]:
                        for w in module[where]:
                            events.append( (w, True, where) )
                    else:
                        for w in module[where]:
                            events.append( (w, False, where) )

                    flip_flops[where] = not flip_flops[where]


            elif where in conjunctions:
                assert _from in conjunctions[where]

                conjunctions[where][_from] = impulse

                # For second part:
                #if where == 'hf' and impulse:
                #    print(pressed_button, _from, impulse)

                if all(conjunctions[where].values()):
                    for w in module[where]:
                        events.append( (w, False, where ) )
                else:
                    for w in module[where]:
                        events.append( (w, True, where ) )

    print(a, b)

run(load_input_file('test_input'))
