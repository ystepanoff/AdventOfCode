from collections import defaultdict
import sys

seeds = []
order = []
all_rules = defaultdict(list)

for line in sys.stdin:
    line = line.rstrip()
    if not line:
        continue
    if line.startswith("seeds:"):
        lst = [int(x) for x in line.split(': ')[1].split()]
        seeds = list(zip(lst[::2], lst[1::2]))
        
    elif line.endswith(":"):
        stage = line.split('-to-')[0]
        order.append(stage)
    else:
        dst, src, l = map(int, line.split())
        all_rules[stage].append((src, l, dst - src))


def process_rules(ranges, rules):
    next_ranges = []
    for range_start, range_len in ranges:
        for rule_start, rule_len, rule_diff in rules:
            if range_start < rule_start < range_start + range_len:
                t = rule_start - range_start
                ranges.append((range_start, t))
                range_start += t
                range_len -= t
            if range_start <= rule_start + rule_len - 1 < range_start + range_len - 1:
                t = range_start + range_len - (rule_start + rule_len)
                ranges.append((rule_start + rule_len, t))
                range_len -= t
            if rule_start <= range_start < rule_start + rule_len:
                next_ranges.append((range_start + rule_diff, range_len))
                break
        else:
            next_ranges.append((range_start, range_len))
    return next_ranges

        
ranges = seeds[:]
for stage in order:
    ranges = process_rules(ranges, all_rules[stage])
print(min(ranges)[0])
