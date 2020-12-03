import random

# bolts = list(range(20))
# random.shuffle(bolts)
bolts = [19, 2, 8, 3, 11, 7, 16, 9, 18, 1, 17, 13, 0, 14, 12, 15, 6, 10, 5, 4]

def Search(a, b, left, right):
    if left == right:
        b[0] = left
        b[1] = left
    elif left == right - 1:
        if a[left] > a[right]:
            b[0] = left
            b[1] = right
        else:
            b[0] = right
            b[1] = left
    else:
        m = (right - left + 1) // 2
        i = left
        while i < left + m:
            a[i], a[i + m] = a[i + m], a[i]
            i += 1
        Search(a, b, left + m, right)
        if a[b[0] - m] > a[b[1]]:
            b[1] = b[0] - m
        print(f'bolts[{b[0]}] = {bolts[b[0]]}')
        print(f'bolts[{b[1]}] = {bolts[b[1]]}')

print(bolts)
b = [0, 0]
Search(bolts, b, 0, len(bolts) - 1)

# print(f'bolts[{x}] = {bolts[x]}')
# print(f'bolts[{y}] = {bolts[y]}')