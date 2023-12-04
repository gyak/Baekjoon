def lotto(nums, index, indexA):
    global temp
    if (index == 6):
        print(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5])
        return
    for i in range(indexA, nums[0]-(6-index)+2):
        # print('index: ', index, 'i: ', i)
        temp[index] = nums[i]
        lotto(nums, index+1, i+1)


arr = []
while (1):
    tempstr = input()
    if (tempstr == '0'):
        break
    arr.append(list(map(int, tempstr.split())))

for caseT in arr:
    temp = [0]*6
    lotto(caseT, 0, 1)
    print('')
