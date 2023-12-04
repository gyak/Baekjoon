n = int(input())

ans = 0
row = [-1]*n


def checkPos(nowRow, nowCol):
    if (nowCol in row):
        return False
    for tempRow in range(nowRow):
        if ((nowCol-row[tempRow])/(nowRow-tempRow) == 1 or (nowCol-row[tempRow])/(nowRow-tempRow) == -1):
            return False
    return True


def solveNqueen(nowRow):
    global ans
    if (nowRow == n):
        ans = ans + 1
        return
    else:
        for nowCol in range(n):
            if (checkPos(nowRow, nowCol) == True):
                row[nowRow] = nowCol
                solveNqueen(nowRow+1)
                row[nowRow] = -1


solveNqueen(0)
print(ans)


# n = int(input())
# for kk in range(1, 15, 1):
#     ans = 0
#     row = [0]*kk

#     def is_promising(x):
#         for i in range(x):
#             if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
#                 return False

#         return True

#     def n_queens(x):
#         # print('check', x)
#         global ans
#         if x == kk:
#             ans += 1
#             return

#         else:
#             for i in range(kk):
#                 # [x, i]에 퀸을 놓겠다.
#                 row[x] = i
#                 if is_promising(x):
#                     n_queens(x+1)

#     n_queens(0)
#     print(ans)
