import random
# bolts = list(range(20))
# random.shuffle(bolts)
bolts = [17, 16, 3, 10, 2, 6, 7, 12, 8, 14, 11, 1, 18, 4, 5, 0, 13, 15, 9, 19]
# nuts = list(range(20))
# random.shuffle(nuts)
nuts = [15, 10, 7, 4, 17, 6, 9, 1, 0, 16, 13, 12, 19, 5, 8, 18, 2, 3, 14, 11]

print(f'bolts: {bolts}')

def machBN(bolts, nuts, left, right):
    if left < right:
        tmp = nuts[right]
        i = left
        j = right
        while i < j:
            while i < j and bolts[i] < tmp:
                i += 1
            while i < j and bolts[j] > tmp:
                j -= 1
            if i < j:
                bolts[i], bolts[j] = bolts[j], bolts[i]
        bolts[right], bolts[i] = bolts[i], bolts[right]  #将目标函数换到最前面
        print("bi", i)
        print(f'bolts:[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]')
        print(f'bolts: {bolts}')
        print(f'nuts: {nuts}')
        i = left
        j = right
        while i < j:
            while i < j and nuts[i] < tmp:
                i += 1
            while i < j and nuts[j] > tmp:
                j -= 1
            if i < j:
                nuts[i], nuts[j] = nuts[j], nuts[i]
        nuts[right], nuts[i] = nuts[i], nuts[right]
        print("in", i)
        print(f'bolts:[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]')
        print(f'bolts: {bolts}')
        print(f'nuts: {nuts}')

        machBN(bolts, nuts, i, right - 1)
        machBN(bolts, nuts, left, i - 1)


machBN(bolts, nuts, 0, len(nuts) - 1)