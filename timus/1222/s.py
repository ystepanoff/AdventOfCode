n = int(input())
dp = [1] * (n + 1)
for i in range(1, n + 1):
    for j in range(1, i + 1):
        dp[i] = max(dp[i], dp[i - j] * j)
print(dp[n])
