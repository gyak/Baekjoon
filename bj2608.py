inputStr1 = input()+' '
inputStr2 = input()+' '
value1 = 0
value2 = 0

romanNum = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500,
            'M': 1000, 'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
for i in range(len(inputStr1)):
    if (inputStr1[i] == 'I'):
        if (inputStr1[i+1] == 'V' or inputStr1[i+1] == 'X'):
            value1 = value1 - 1
        else:
            value1 = value1 + 1
    elif (inputStr1[i] == 'X'):
        if (inputStr1[i+1] == 'L' or inputStr1[i+1] == 'C'):
            value1 = value1 - 10
        else:
            value1 = value1 + 10
    elif (inputStr1[i] == 'C'):
        if (inputStr1[i+1] == 'D' or inputStr1[i+1] == 'M'):
            value1 = value1 - 100
        else:
            value1 = value1 + 100
    elif (inputStr1[i] == 'V'):
        value1 = value1 + 5
    elif (inputStr1[i] == 'L'):
        value1 = value1 + 50
    elif (inputStr1[i] == 'D'):
        value1 = value1 + 500
    elif (inputStr1[i] == 'M'):
        value1 = value1 + 1000

for i in range(len(inputStr2)):
    if (inputStr2[i] == 'I'):
        if (inputStr2[i+1] == 'V' or inputStr2[i+1] == 'X'):
            value2 = value2 - 1
        else:
            value2 = value2 + 1
    elif (inputStr2[i] == 'X'):
        if (inputStr2[i+1] == 'L' or inputStr2[i+1] == 'C'):
            value2 = value2 - 10
        else:
            value2 = value2 + 10
    elif (inputStr2[i] == 'C'):
        if (inputStr2[i+1] == 'D' or inputStr2[i+1] == 'M'):
            value2 = value2 - 100
        else:
            value2 = value2 + 100
    elif (inputStr2[i] == 'V'):
        value2 = value2 + 5
    elif (inputStr2[i] == 'L'):
        value2 = value2 + 50
    elif (inputStr2[i] == 'D'):
        value2 = value2 + 500
    elif (inputStr2[i] == 'M'):
        value2 = value2 + 1000

hap = value1 + value2
print(hap)
outputStr = ''

while (1):
    if (hap >= 1000):
        target = 'M'
    elif (hap >= 900):
        target = 'CM'
    elif (hap >= 500):
        target = 'D'
    elif (hap >= 400):
        target = 'CD'
    elif (hap >= 100):
        target = 'C'
    elif (hap >= 90):
        target = 'XC'
    elif (hap >= 50):
        target = 'L'
    elif (hap >= 40):
        target = 'XL'
    elif (hap >= 10):
        target = 'X'
    elif (hap >= 9):
        target = 'IX'
    elif (hap >= 5):
        target = 'V'
    elif (hap >= 4):
        target = 'IV'
    elif (hap >= 1):
        target = 'I'
    hap = hap - romanNum[target]
    outputStr = outputStr + target
    if (hap == 0):
        break
print(outputStr)
