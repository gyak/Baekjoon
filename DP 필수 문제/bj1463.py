n = int(input())

his = [0]*(n+1)
his[1] = 0
if (n > 1):
    his[2] = 1
if (n > 2):
    his[3] = 1

for i in range(4, n+1, 1):
    if i % 6 == 0:
        his[i] = min(his[int(i/3)], his[int(i/2)], his[i-1]) + 1
    elif i % 3 == 0:
        his[i] = min(his[int(i/3)], his[i-1])+ 1
    elif i % 2 == 0:
        his[i] = min(his[int(i/2)], his[i-1]) + 1
    else:
        his[i] = his[i-1] + 1

print(his[n])
