import math
n = int(input())
t = math.floor(n**0.5)
dp = [[0]*(n+1) for _ in range(t+1)]
for j in range(n+1):
    dp[1][j] = j
for i in range(2, t+1, 1):
    for j in range(1, n+1, 1):
        if (j < i*i):
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = min(dp[i-1][j], dp[i][j-i*i]+1)
print(dp[t][n])
