state = list(map(int, input().split(',')))
for i in range(80):
    add = 0
    for j, c in enumerate(state):
        if c == 0:
            add += 1
            state[j] = 6
        else:
            state[j] -= 1
    state.extend([8] * add)
print(len(state))
