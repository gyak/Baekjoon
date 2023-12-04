import copy


def devideRG(leng, red, green, etc):
    global hwang, tempRG, rg, r, g
    if (red == 0 and green == 0 and leng == len(hwang)):
        rg.append(tempRG.copy())
        return
    elif (leng == len(hwang)):
        return
    if (red != 0):
        tempRG[leng] = 'r'
        devideRG(leng+1, red-1, green, etc)
    if (green != 0):
        tempRG[leng] = 'g'
        devideRG(leng+1, red, green-1, etc)
    if (etc != 0):
        tempRG[leng] = 'x'
        devideRG(leng+1, red, green, etc-1)


def queueBfs(q):
    global check, garden
    qLen = len(q)
    for i in range(qLen):
        tr, tc = q[i]
        if (tr > 0 and check[tr-1][tc] == 0 and garden[tr-1][tc] != 0):
            if (((tr-1, tc) in q) == False):
                q.append((tr-1, tc))
                # print('false')
            # else:
            #     print('q: ', q, tr-1, tc)
        if (tr < n-1 and check[tr+1][tc] == 0 and garden[tr+1][tc] != 0):
            if (((tr+1, tc) in q) == False):
                q.append((tr+1, tc))
            # else:
            #     print('q: ', q, tr+1, tc)
        if (tc > 0 and check[tr][tc-1] == 0 and garden[tr][tc-1] != 0):
            if (((tr, tc-1) in q) == False):
                q.append((tr, tc-1))
            # else:
            #     print('q: ', q, tr, tc-1)
        if (tc < m-1 and check[tr][tc+1] == 0 and garden[tr][tc+1] != 0):
            if (((tr, tc+1) in q) == False):
                q.append((tr, tc+1))
            # else:
            #     print('q: ', q, tr, tc+1)
    return q[qLen:]


def qq(redq, greenq):
    global check, garden
    tempRed = copy.deepcopy(redq)
    tempGreen = copy.deepcopy(greenq)
    tempFlower = 0
    redLen = len(tempRed)
    for i in range(redLen):
        tr, tc = tempRed[i]
        if (tr > 0 and check[tr-1][tc] == 0 and garden[tr-1][tc] != 0):
            tempRed.append((tr-1, tc))
            check[tr-1][tc] = 2
        if (tr < n-1 and check[tr+1][tc] == 0 and garden[tr+1][tc] != 0):
            tempRed.append((tr+1, tc))
            check[tr+1][tc] = 2
        if (tc > 0 and check[tr][tc-1] == 0 and garden[tr][tc-1] != 0):
            tempRed.append((tr, tc-1))
            check[tr][tc-1] = 2
        if (tc < m-1 and check[tr][tc+1] == 0 and garden[tr][tc+1] != 0):
            tempRed.append((tr, tc+1))
            check[tr][tc+1] = 2

    greenLen = len(tempGreen)
    for i in range(greenLen):
        tr, tc = tempGreen[i]
        if (tr > 0 and check[tr-1][tc] != 1 and garden[tr-1][tc] != 0):
            if (check[tr-1][tc] == 2):
                tempFlower = tempFlower + 1
                tempRed.remove((tr-1, tc))
            elif (check[tr-1][tc] == 0):
                tempGreen.append((tr-1, tc))
            check[tr-1][tc] = 1
        if (tr < n-1 and check[tr+1][tc] != 1 and garden[tr+1][tc] != 0):
            if (check[tr+1][tc] == 2):
                tempFlower = tempFlower + 1
                tempRed.remove((tr+1, tc))
            elif (check[tr+1][tc] == 0):
                tempGreen.append((tr+1, tc))
            check[tr+1][tc] = 1
        if (tc > 0 and check[tr][tc-1] != 1 and garden[tr][tc-1] != 0):
            if (check[tr][tc-1] == 2):
                tempFlower = tempFlower + 1
                tempRed.remove((tr, tc-1))
            elif (check[tr][tc-1] == 0):
                tempGreen.append((tr, tc-1))
            check[tr][tc-1] = 1
        if (tc < m-1 and check[tr][tc+1] != 1 and garden[tr][tc+1] != 0):
            if (check[tr][tc+1] == 2):
                tempFlower = tempFlower + 1
                tempRed.remove((tr, tc+1))
            elif (check[tr][tc+1] == 0):
                tempGreen.append((tr, tc+1))
            check[tr][tc+1] = 1

    for i in range(len(tempRed)):
        check[tempRed[i][0]][tempRed[i][1]] = 1

    return tempRed[redLen:], tempGreen[greenLen:], tempFlower


def queueCheck(redq, greenq):
    global check
    tempRed = copy.deepcopy(redq)
    tempGreen = copy.deepcopy(greenq)
    tempFlower = 0
    # print(redq, greenq)
    for i in range(len(redq)):
        if (redq[i] in greenq):
            # print('flower: ', redq[i][0], redq[i][1])
            tempFlower = tempFlower + 1
            check[redq[i][0]][redq[i][1]] = 1
            tempRed.remove(redq[i])
            tempGreen.remove(redq[i])
    for i in range(len(tempRed)):
        check[tempRed[i][0]][tempRed[i][1]] = 1
    for i in range(len(tempGreen)):
        check[tempGreen[i][0]][tempGreen[i][1]] = 1
    return tempRed, tempGreen, tempFlower


def solveGarden(nowRG):
    global flower, check, hwang
    redq = []
    greenq = []
    tempFlower = 0
    for j in range(len(nowRG)):
        if (nowRG[j] == 'r'):
            redq.append(hwang[j])
            check[hwang[j][0]][hwang[j][1]] = 1
        elif (nowRG[j] == 'g'):
            greenq.append(hwang[j])
            check[hwang[j][0]][hwang[j][1]] = 1
    while (1):
        if (len(redq) == 0 or len(greenq) == 0):
            break

        redq, greenq, temp = qq(redq, greenq)
        tempFlower = tempFlower + temp
    flower.append(tempFlower)


n, m, g, r = map(int, input().split())
garden = []
hwang = []
flower = []
# print(temp)
rg = []
for i in range(n):
    garden.append(list(map(int, input().split())))
    for j in range(m):
        if (garden[i][j] == 2):
            hwang.append((i, j))
        # elif (garden[i][j] == 0):
        #     check[i][j] = 1

tempRG = [0]*(len(hwang))
devideRG(0, r, g, len(hwang)-r-g)
for i in range(len(rg)):
    # print('---------------------')
    # print(rg[i])

    check = [[0]*m for _ in range(n)]
    solveGarden(rg[i])
# print('hwang', hwang)
# print('rg', rg)
# print('flower', flower)
print(max(flower))
