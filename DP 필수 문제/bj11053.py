n = int(input())
arr = list(map(int, input().split()))
dp = [1]*n

for j in range(1, n, 1):
    maxTemp = 0
    for k in range(j):
        if (arr[j] > arr[k]):
            if (dp[k] > maxTemp):
                maxTemp = dp[k]
    dp[j] = maxTemp + 1
print(max(dp))
