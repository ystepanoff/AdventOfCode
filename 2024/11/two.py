from collections import defaultdict


def count(st):
    s = defaultdict(int)
    s[st] = 1
    for _ in range(75):
        new_s = defaultdict(int)
        for stone, cnt in s.items():
            str_stone = str(stone)
            l = len(str_stone)
            if stone == 0:
                new_s[1] += cnt
            elif l % 2 == 0:
                mid = l // 2
                new_s[int(str_stone[:mid])] += cnt
                new_s[int(str_stone[mid:])] += cnt
            else:
                new_s[stone * 2024] += cnt
        s = new_s
    return sum(s.values())


print(sum(count(int(s)) for s in input().split()))
