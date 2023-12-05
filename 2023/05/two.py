import sys

input_data = sys.stdin.read().strip()
input_lines = input_data.split('\n')

sections = input_data.split('\n\n')

seed, *other_sections = sections
seed = [int(x) for x in seed.split(':')[-1].split()]

class Function:
    def __init__(self, section_str):
        lines = section_str.split('\n')[1:]
        self.tuples = [[int(x) for x in line.split()] for line in lines]

    def apply_range(self, range_list):
        new_ranges = []
        for (dest, src, sz) in self.tuples:
            src_end = src + sz
            next_ranges = []
            while range_list:
                (st, ed) = range_list.pop()
                before = (st, min(ed, src))
                inter = (max(st, src), min(src_end, ed))
                after = (max(src_end, st), ed)
                if before[1] > before[0]:
                    next_ranges.append(before)
                if inter[1] > inter[0]:
                    new_ranges.append((inter[0] - src + dest, inter[1] - src + dest))
                if after[1] > after[0]:
                    next_ranges.append(after)
            range_list = next_ranges
        return new_ranges + range_list

functions = [Function(section) for section in other_sections]

result = []
pairs = list(zip(seed[::2], seed[1::2]))
for start, size in pairs:
    current_range = [(start, start + size)]
    for func in functions:
        current_range = func.apply_range(current_range)
    result.append(min(current_range)[0])
print(min(result))
