import re
import sys

mul_pattern = re.compile(r"mul\((\d+),(\d+)\)")
ctrl_pattern = re.compile(r"(do|don't)\(\)")

input_str = sys.stdin.read()
total, ctrl = 0, 1
for match in re.finditer(r"(mul\(\d+,\d+\)|do\(\)|don't\(\))", input_str):
    instruction = match.group(1)
    mul_match = mul_pattern.match(instruction)
    ctrl_match = ctrl_pattern.match(instruction)
    if mul_match:
        a, b = map(int, mul_match.groups())
        total += a * b * ctrl
    elif ctrl_match:
        if ctrl_match.group(1) == 'do':
            ctrl = 1
        else:
            ctrl = 0
print(total)
