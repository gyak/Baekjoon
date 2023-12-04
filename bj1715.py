import heapq
n = int(input())
arr = []
for i in range(n):
    heapq.heappush(arr, int(input()))
ans = 0
while (len(arr) != 1):
    temp = heapq.heappop(arr) + heapq.heappop(arr)
    ans = ans + temp
    heapq.heappush(arr, temp)
print(ans)
