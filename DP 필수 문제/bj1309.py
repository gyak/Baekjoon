n = int(input())
dp = [[1]*2 for _ in range(n)]

for i in range(1, n, 1):
    dp[i][0] = (dp[i-1][0] + 2*dp[i-1][1])%9901
    dp[i][1] = (dp[i-1][0] + dp[i-1][1])%9901

print((dp[n-1][0]+2*dp[n-1][1])%9901)
