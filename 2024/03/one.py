import re
import sys

input_str = sys.stdin.read()
total = 0
parts = input_str.split("mul")
for part in parts:
    match = re.match(r"^\((\d+),(\d+)\)", part)
    if match:
        a = int(match.group(1))
        b = int(match.group(2))
        total += a * b
print(total)
