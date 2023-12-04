n = int(input())
arr = [0]
ansTemp = []
for _ in range(n):
    arr.append(int(input()))
dp = [0]*(n+1)

dp[0] = arr[0]
dp[1] = arr[1]
if (n > 1):
    dp[2] = arr[2]+arr[1]
for j in range(3, n+1, 1):
    dp[j] = max(dp[j-3] + arr[j-1] + arr[j], dp[j-2] + arr[j])
print(dp[n])
