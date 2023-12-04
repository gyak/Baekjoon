n = int(input())
bamboo = []
sortedList = []
dp = [[1]*n for _ in range(n)]
for i in range(n):
    bamboo.append(list(map(int, input().split())))
    for j in range(n):
        sortedList.append((i, j, bamboo[i][j]))
sortedList.sort(key=lambda x: x[2], reverse=True)
# print(sortedList)

for k in sortedList:
    if (k[0] != n-1):
        if (bamboo[k[0]][k[1]] > bamboo[k[0]+1][k[1]]):
            dp[k[0]+1][k[1]] = max(dp[k[0]+1][k[1]], dp[k[0]][k[1]]+1)
    if (k[1] != n-1):
        if (bamboo[k[0]][k[1]] > bamboo[k[0]][k[1]+1]):
            dp[k[0]][k[1]+1] = max(dp[k[0]][k[1]+1], dp[k[0]][k[1]]+1)
    if (k[0] != 0):
        if (bamboo[k[0]][k[1]] > bamboo[k[0]-1][k[1]]):
            dp[k[0]-1][k[1]] = max(dp[k[0]-1][k[1]], dp[k[0]][k[1]]+1)
    if (k[1] != 0):
        if (bamboo[k[0]][k[1]] > bamboo[k[0]][k[1]-1]):
            dp[k[0]][k[1]-1] = max(dp[k[0]][k[1]-1], dp[k[0]][k[1]]+1)


# print(max(dp))
# print(dp)
max = 1
for i in range(n):
    for j in range(n):
        if (dp[i][j] > max):
            max = dp[i][j]
        # print(dp[i][j], end=' ')
    # print('')
print(max)
