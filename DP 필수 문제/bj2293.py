n, k = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))
dp = [0]*(k+1)
dp[0] = 1
for i in range(n):
    for j in range(arr[i], k+1, 1):
        if (j >= arr[i]):
            dp[j] = dp[j] +dp[j-arr[i]]
print(dp[k])

# for j in range(0, k+1, 1):
#     # tempList = []
#     for i in range(n):
#         if (j >= arr[i]):
#             dp[j] = dp[j] + dp[j-arr[i]]
#             # tempList.append(dp[j-arr[i]]+1)
#     # dp[j] = len(tempList)
#     # if (tempList):
#     #     dp[j] = min(tempList)
#     # else:
#     #     dp[j] = -1

# print(dp)
