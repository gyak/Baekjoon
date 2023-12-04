n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
maxNum = max(arr)
dp = [[0]*(maxNum+1) for _ in range(4)]
for j in range(maxNum+1):
    dp[1][j] = 1
for i in range(2, 4, 1):
    dp[i][1] = 1
    for j in range(2, maxNum+1, 1):
        if (j < i):
            dp[i][j] = dp[i-1][j]
        elif (j == i):
            dp[i][j] = dp[i-1][j] + 1
        else:
            for k in range(i):
                dp[i][j] = dp[i][j] + dp[i][j-k-1]
for k in range(n):
    print(dp[3][arr[k]])
