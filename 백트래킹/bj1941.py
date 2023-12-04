from queue import Queue


def bfs(row, col, som, len):
    global ans
    if (len == 7):
        if (som > 3):
            ans = ans + 1
        return
    if (arr[row][col] == 'S'):
        som = som + 1
    if (row < 4):
        bfs(row+1, col, som, len+1)
    if (col < 4):
        bfs(row, col+1, som, len+1)

    q = Queue()
    while (1):

        if (row < 4):
            q.put((row+1, col))
        if (col < 4):
            q.put((row, col+1))
        if (col > 0):
            q.put((row, col-1))


ans = 0
arr = []
for i in range(5):
    arr.append(input())

for i in range(5):
    for j in range(5):
        bfs(i, j, 0, 0)
print(ans)
