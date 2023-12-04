n = int(input())
ans = 0
dp = [[0]*10 for _ in range(n)]

for j in range(10):
    dp[0][j] = 1
for i in range(1, n, 1):
    dp[i][0] = 1
    for j in range(1, 10, 1):
        dp[i][j] = (dp[i][j-1] + dp[i-1][j])%10007
    
for j in range(10):
    ans = (ans + dp[n-1][j])%10007
print(ans)