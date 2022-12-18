import re
pattern = re.compile(r'Valve (.*) has flow rate=(\d*); tunnels? leads? to valves? (.+)')
G = {}
for line in open('input'):
    line = line.rstrip()
    match = pattern.match(line)
    v = match.group(1)
    r = int(match.group(2))
    ch = match.group(3).split(', ')
    G[v] = {
        'rate': r,
        'children': ch,
    }

CACHE = {}
def dp(v='AA', opened=set(), time=26, first=True):
    global CACHE, G
    if time == 0:
        return dp('AA', opened, 26, False) if first else 0
    key = (v, str(sorted(list(opened))), time, first)
    if key in CACHE:
        return CACHE[key]
    result = 0
    for ch in G[v]['children']:
        result = max(result, dp(ch, opened, time - 1, first))
    if v not in opened and G[v]['rate'] > 0:
        result = max(result, (time - 1) * G[v]['rate'] + dp(v, opened.union({v}), time - 1, first))
    CACHE[key] = result
    return result

print(dp())
