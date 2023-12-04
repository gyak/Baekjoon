n = int(input())
fiboArr = [0]*(n+2)
fiboArr[1] = 1
fiboArr[2] = 1
for i in range(3, n+1, 1):
    fiboArr[i] = fiboArr[i-1]+fiboArr[i-2]
print(fiboArr[n])
