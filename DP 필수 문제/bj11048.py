n, m = map(int, input().split())
candy = []
dp = [[0]*m for _ in range(n)]
for i in range(n):
    candy.append(list(map(int, input().split())))

dp[0][0] = candy[0][0]
for i in range(1, n, 1):
    dp[i][0] = dp[i-1][0] + candy[i][0]
for j in range(1, m, 1):
    dp[0][j] = dp[0][j-1] + candy[0][j]
for i in range(1, n, 1):
    for j in range(1, m, 1):
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + candy[i][j]

print(dp[n-1][m-1])
