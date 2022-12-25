VIS = set()
G = {}
def dfs(v):
    global G, VIS
    VIS.add(v)
    for ch in G[v]['ch']:
        if ch not in VIS:
            dfs(ch)
    if G[v]['value'] is None:
        a, b = [G[u]['value'] for u in G[v]['ch']]
        match G[v]['op']:
            case '+':
                G[v]['value'] = a + b
            case '-':
                G[v]['value'] = a - b
            case '*':
                G[v]['value'] = a * b
            case '/':
                G[v]['value'] = a // b

G = {}
for line in open('input'):
    v, value = line.rstrip().split(': ')
    if v not in G:
        G[v] = {}
    try:
        G[v]['value'] = int(value)
        G[v]['ch'] = []
        G[v]['op'] = ''
    except ValueError:
        G[v]['value'] = None
        a, op, b = value.split()
        G[v]['ch'] = [a, b]
        G[v]['op'] = op
dfs('root')
print(G['root']['value'])
