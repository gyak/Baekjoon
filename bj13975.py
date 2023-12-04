import heapq
t = int(input())
ans = []
for _ in range(t):
    k = int(input())
    # arr = []
    arr = list(map(int, input().split()))
    arr.sort()
    # for i in range(k):
    # heapq.heappush(arr, int(input()))
    ansNum = 0
    while (len(arr) != 1):
        t1 = heapq.heappop(arr)
        t2 = heapq.heappop(arr)
        # print(t1, t2)
        # temp = heapq.heappop(arr) + heapq.heappop(arr)
        temp = t1 + t2
        ansNum = ansNum + temp
        heapq.heappush(arr, temp)
    # print(ans)
    ans.append(ansNum)
for _ in ans:
    print(_)
