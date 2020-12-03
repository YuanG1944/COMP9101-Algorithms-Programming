def judgeSquareSum_fi(num):
    #Set a dic to contain squares of two distinct numbers
    numDic = {}
    #Return value
    count = bool(0)

    for i in range(0, len(num) - 1):
        for j in range(i, len(num)):
            #Get squares of two distinct numbers sqSum
            sqSum = num[i] * num[i] + num[j] * num[j]
            #Search whether sqSUM already exist in numDic
            #if yes returen true
            #else append it in the numDic
            if str(sqSum) in numDic.keys():
                count = bool(1)
                break
            else:
                numDic[str(sqSum)] = [1]
    print(numDic)
    return count



num = [3, 4, 2, 0, 1, 5]
print(num)
count = judgeSquareSum_fi(num)
print(count)