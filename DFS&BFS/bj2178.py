from queue import Queue


def bfs(now):
    global mirro, n, m
    stack = []
    visit = [[0]*m for _ in range(n)]
    row = 0
    col = 0
    ans = 0
    while (1):
        check = 0
        for i in range(n+1):
            if (graph[now][i] == 1 and visit[i] == 0):
                print(i, end=' ')
                visit[i] = 1
                stack.append(now)
                now = i
                check = 1
                break
        if (len(stack) == 0):
            break
        if (check == 0):
            now = stack.pop()


n, m = map(int, input().split())
mirro = []
for i in range(n):
    mirro.append(input())
ans = bfs()
print(ans)
