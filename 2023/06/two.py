import math
import re
import sys

times, dists = sys.stdin.read().split('\n')[:2]
time = int(''.join(re.findall(r'\d+', times)))
dist = int(''.join(re.findall(r'\d+', dists)))

j_left = max(0, int((time / 2) - math.sqrt((time ** 2) / 4 - dist)))
j_right = min(dist, int((time / 2) + math.sqrt((time ** 2) / 4 - dist)))
print(j_right - j_left)

# (time - j) * j > dist
# j^2 - time * j + dist < 0
# (j - time / 2)^2 + dist - (time^2 / 4) < 0
# (j - time / 2)^2 < (time^2 / 4) - dist
# -sqrt((time^2 / 4) - dist) < j - time / 2 < sqrt((time^2 / 4) - dist)
# (time / 2) - sqrt((time^2 / 4) - dist) < j < (time / 2) + sqrt((time^2 / 4) - dist)
