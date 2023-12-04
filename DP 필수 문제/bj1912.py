n = int(input())
arr = list(map(int, input().split()))
dp = [0]*n
dp[0] = arr[0]

for j in range(1, n, 1):
    if (dp[j-1] < 0):
        dp[j] = arr[j]
    else:
        dp[j] = dp[j-1]+arr[j]
print(max(dp))
