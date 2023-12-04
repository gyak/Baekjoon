n, k = map(int, input().split())
DP = [[0]*(k+1) for i in range(n+1)]
W = [0]*(n+1)
V = [0]*(n+1)

for i in range(1, n+1):
    W[i], V[i] = map(int, input().split())

for i in range(1, n+1):
    for j in range(1, k+1):
        if j - W[i] >= 0:
            DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]]+V[i])
        else:
            DP[i][j] = DP[i-1][j]
print(DP[n][k])
