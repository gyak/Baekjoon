n, k = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))
dp = [-1]*(k+1)
for j in range(1, k+1, 1):
    tempList = []
    for i in range(n):
        if (j == arr[i]):
            tempList.append(1)
        if (j > arr[i] and dp[j-arr[i]] > 0):
            tempList.append(dp[j-arr[i]]+1)
    if (tempList):
        dp[j] = min(tempList)
    else:
        dp[j] = -1

print(dp[k])
