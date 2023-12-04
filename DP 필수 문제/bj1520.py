n, m = map(int, input().split())
height = []
sortedList = []
dp = [[0]*m for _ in range(n)]
for i in range(n):
    height.append(list(map(int, input().split())))
    for j in range(m):
        sortedList.append((i, j, height[i][j]))
sortedList.sort(key=lambda x: x[2], reverse=True)
# print(sortedList)
dp[0][0] = 1
for k in sortedList:
    if (k[0] != n-1):
        # if (k[2] == 20):
        #     print(height[k[0]][k[1]], height[k[0]+1][k[1]], dp[k[0]+1][k[1]])
        if (height[k[0]][k[1]] < height[k[0]+1][k[1]]):
            dp[k[0]][k[1]] = dp[k[0]][k[1]] + dp[k[0]+1][k[1]]
    if (k[1] != m-1):
        # if (k[2] == 20):
        #     print(height[k[0]][k[1]], height[k[0]][k[1]+1], dp[k[0]][k[1]+1])
        if (height[k[0]][k[1]] < height[k[0]][k[1]+1]):
            dp[k[0]][k[1]] = dp[k[0]][k[1]] + dp[k[0]][k[1]+1]
    if (k[0] != 0):
        # if (k[2] == 20):
        #     print(height[k[0]][k[1]], height[k[0]-1][k[1]], dp[k[0]-1][k[1]])
        if (height[k[0]][k[1]] < height[k[0]-1][k[1]]):
            dp[k[0]][k[1]] = dp[k[0]][k[1]] + dp[k[0]-1][k[1]]
    if (k[1] != 0):
        # if (k[2] == 20):
        #     print(height[k[0]][k[1]], height[k[0]][k[1]-1], dp[k[0]][k[1]-1])
        if (height[k[0]][k[1]] < height[k[0]][k[1]-1]):
            dp[k[0]][k[1]] = dp[k[0]][k[1]] + dp[k[0]][k[1]-1]

print(dp[n-1][m-1])
# for i in range(n):
#     for j in range(m):
#         print(dp[i][j], end=' ')
#     print('')
