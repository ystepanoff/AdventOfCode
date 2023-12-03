from collections import defaultdict
import sys

grid = []
for line in sys.stdin:
    grid.append(line.rstrip())
n, m = len(grid), len(grid[0])
total = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == '*':
            nums = set()
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if x >= 0 and y >= 0 and x < n and y < m and grid[x][y].isdigit():
                        l, r = y, y
                        while l > 0 and grid[x][l - 1].isdigit():
                            l -= 1
                        while r < m and grid[x][r].isdigit():
                            r += 1
                        nums.add((int(grid[x][l:r]), x, l, r))
            if len(nums) == 2:
                nums = list(nums)
                total += nums[0][0] * nums[1][0]
print(total)

