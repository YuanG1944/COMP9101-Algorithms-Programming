import numpy as np
import matplotlib.pyplot as plt

x = [1, 0, 0, 0, 1]
x = np.array(x)
print(x)
# wave=np.cos(x)
transformed = np.fft.fft(x) #傅里叶变换
print(transformed)
# plt.plot(transformed) #绘制变换后的信号