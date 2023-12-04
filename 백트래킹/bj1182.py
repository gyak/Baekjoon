def count_subsequences_with_sum(arr, S):
    def backtrack(index, current_sum):
        if current_sum == S:
            # 합이 S가 되는 부분수열을 찾았을 때
            nonlocal count
            count += 1
            return
        if index == len(arr) or current_sum > S:
            # 배열 끝에 도달하거나 현재 합이 S를 초과한 경우
            return

        # 현재 원소를 부분수열에 포함하는 경우
        backtrack(index + 1, current_sum + arr[index])

        # 현재 원소를 부분수열에 포함하지 않는 경우
        backtrack(index + 1, current_sum)

    count = 0
    backtrack(0, 0)
    return count


# 예시 사용법
# arr = [1, 2, 3, 4, 5]
# S = 5


n, s = map(int, input().split())
arr = list(map(int, input().split()))
result = count_subsequences_with_sum(arr, s)
print(result)


# def computeSum(index, nowSum):
#     # print(index, nowSum, nowLen)
#     global ans, n, s
#     if (index == n):
#         return
#     if (nowSum == s):
#         # print('check')
#         ans = ans + 1
#     # if(nowSum == ):

#     computeSum(index+1, nowSum+arr[index+1])
#     computeSum(index+1, nowSum)


# n, s = map(int, input().split())
# arr = list(map(int, input().split()))
# arr.append(0)
# ans = 0
# # for j in range(n):
# #     computeSum(j, arr[j])
# # print('--------------')
# computeSum(1, arr[0])
# computeSum(1, 0)
# print(ans)
