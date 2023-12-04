n = int(input())

dp = [0]*31
dp[0] = 1
dp[2] = 3

# dp[n] = dp[n-2]*dp[2] + dp[n-4]*2 + dp[n-6]*2 + ... + dp[2]*2 + 2
for j in range(4, n+1, 2):
    dp[j] = dp[j-2]*3
    for k in range(j-4, -1, -2):
        dp[j] = dp[j] + dp[k]*2
print(dp[n])
