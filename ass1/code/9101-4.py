
a = [[],[],[],[]] # 树矩阵
n # 数量n
b = -1  # 最大值
c  # temp
ii # ii为最大值子矩阵的右下角元素横坐标
jj # jj为最大值子矩阵的右下角元素纵坐标

a.insert(0, [0] * n)

for i in range(4n):
	a[i].insert(0, 0)

for i in range(1, 4n + 1):
	for j in range(1, 4n + 1):
		a[i][j] += (a[i - 1][j] + a[i][j - 1] - a[i][j])
		if i >= n and j >= n:
			c = a[i][j] - a[i - n][j] - a[i][j - n] + a[i - n][j - n]
			if m > b:
				b = c
				ii = i
				jj = j

# c 为最大值
# ii为最大值子矩阵的右下角元素横坐标
# jj为最大值子矩阵的右下角元素纵坐标

                                                                     

