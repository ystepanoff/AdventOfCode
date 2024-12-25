T = input().split(", ")
input()
total = 0
try:
    while s := input():
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(1, len(s) + 1):
            for t in T:
                if i >= len(t) and s[i - len(t):i] == t:
                    dp[i] |= dp[i - len(t)]
        total += dp[-1]
except EOFError:
    pass
print(total)
