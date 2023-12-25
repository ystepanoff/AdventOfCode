from collections import defaultdict
from functools import cmp_to_key
import sys

CARDS = "23456789TJQKA"

def hand_type(hand):
    a = defaultdict(int)
    b = defaultdict(int)
    for c in hand:
        a[c] += 1
    for c in a.values():
        b[c] += 1
    if b[5] == 1:
        return 1
    elif b[4] == 1:
        return 2
    elif b[3] == 1 and b[2] == 1:
        return 3
    elif b[3] == 1 and b[1] == 2:
        return 4
    elif b[2] == 2:
        return 5
    elif b[2] == 1 and b[1] == 3:
        return 6
    else:
        assert b[1] == 5
    return 7


def compare_hands(hand_a, hand_b):
    hand_a = hand_a[0]
    hand_b = hand_b[0]
    t_a = hand_type(hand_a)
    t_b = hand_type(hand_b)
    if t_a < t_b:
        return -1
    if t_a > t_b:
        return 1
    for i in range(len(hand_a)):
        if hand_a[i] == hand_b[i]:
            continue
        if CARDS.index(hand_a[i]) > CARDS.index(hand_b[i]):
            return -1
        else:
            return 1
    return 0


hands = []

for line in sys.stdin:
    cards, rank = line.split()
    rank = int(rank)
    hands.append((cards, rank))

total = 0
for i, hand in enumerate(sorted(hands, key=cmp_to_key(compare_hands))[::-1]):
    total += hand[1] * (i + 1)
print(total)
