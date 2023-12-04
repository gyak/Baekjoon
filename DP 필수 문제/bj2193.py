n = int(input())
arr = [(0, 0), (1, 0), (1, 0)]
for k in range(3, n+1, 1):
    arr.append((arr[k-1][1], arr[k-1][0]+arr[k-1][1]))
print(arr[n][0]+2*arr[n][1])
