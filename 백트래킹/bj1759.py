def password(indexA, indexN):
    global ans, nums, l, c
    if (indexA == l):
        tempAns = ''
        moCheck = 0
        jaCheck = 0
        for i in ans:
            if (i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'):
                moCheck = moCheck + 1
            else:
                jaCheck = jaCheck + 1
            tempAns = tempAns + i
        if (moCheck > 0 and jaCheck > 1):
            print(tempAns)
        return
    for i in range(indexN, c-(l-indexA)+1):
        ans[indexA] = nums[i]
        password(indexA+1, i+1)


l, c = map(int, input().split())
nums = list(map(str, input().split()))
nums.sort()
ans = [0]*l
password(0, 0)
