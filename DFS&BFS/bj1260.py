from queue import Queue


def dfs(now):
    global n
    stack = []
    visit = [0]*(n+1)
    visit[now] = 1
    print(now, end=' ')
    stack.append(now)
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


def bfs(now):
    global n
    q = Queue()
    visit = [0]*(n+1)
    visit[now] = 1
    print(now, end=' ')
    # print('n: ', n)
    while (1):
        for i in range(n+1):
            if (graph[now][i] == 1 and visit[i] == 0):
                print(i, end=' ')
                visit[i] = 1
                q.put(i)
        if (q.empty() == True):
            break
        now = q.get()


n, m, v = map(int, input().split())
graph = [[0]*(n+1) for _ in range(n+1)]
for i in range(m):
    t1, t2 = map(int, input().split())
    graph[t1][t2] = 1
    graph[t2][t1] = 1


dfs(v)
print('')
bfs(v)
