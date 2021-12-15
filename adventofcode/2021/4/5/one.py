import sys


def win(board, numbers):
    h, v = [0] * 5, [0] * 5
    s = 0
    for i in range(5):
        for j in range(5):
            if board[i][j] in numbers:
                h[i] += 1
                v[j] += 1
            else:
                s += board[i][j]
    if not (5 in h or 5 in v):
        s = -1
    return s


nums = map(int, input().split(','))
boards = []
for line in sys.stdin:
    line = line.strip()
    if not line:
        board = []
    else:
        board.append(list(map(int, line.split())))
    if board:
        boards.append(board)

curr_nums = []
for num in nums:
    curr_nums.append(num)
    found = False
    for board in boards:
        s = win(board, curr_nums)
        if s != -1:
            print(s * num)
            found = True
            break
    if found:
        break
