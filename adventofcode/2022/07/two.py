FS = {}
stack = []
lines = [line.strip() for line in open('input')]
curr = 0
while curr < len(lines):
    w = lines[curr].split()
    if w[0] == '$':
        if w[1] == 'cd':
            if w[2] == '..':
                stack.pop()
            else:
                stack.append(w[2])
                FS.setdefault('/'.join(stack), {'dirs': [], 'files': [], 'size': 0})
            curr += 1
        elif w[1] == 'ls':
            curr += 1
            pwd = '/'.join(stack)
            while curr < len(lines) and not lines[curr].startswith('$'):
                param, name = lines[curr].split()
                if param == 'dir':
                    FS[pwd]['dirs'].append('{}/{}'.format(pwd, name))
                else:
                    FS[pwd]['files'].append({'name': name, 'size': int(param)})
                curr += 1


def count_sizes(pwd='/'):
    for d in FS[pwd]['dirs']:
        count_sizes(d)
    FS[pwd]['size'] = sum(FS[d]['size'] for d in FS[pwd]['dirs']) + \
                      sum(f['size'] for f in FS[pwd]['files'])


count_sizes('/')
total = 70000000
need = 30000000
free = total - FS['/']['size']
best = '/'
for d in FS:
    if free + FS[d]['size'] >= need and FS[d]['size'] < FS[best]['size']:
        best = d
print(FS[best]['size'])
