#!/usr/bin/env python
# -*- coding: gbk -*-

###########################
#Numpy详细教程学习
#参考网址：https://blog.csdn.net/a373595475/article/details/79580734
###########################

import numpy as np
import numpy.matlib
from matplotlib import pyplot as plt

x = np.arange(1, 11)
y = 2 * x + 5
plt.title("matplotlib demo")
plt.xlabel("x axis caption")
plt.ylabel("y axis caption")
plt.plot(x, y, 'ob')
plt.show()
