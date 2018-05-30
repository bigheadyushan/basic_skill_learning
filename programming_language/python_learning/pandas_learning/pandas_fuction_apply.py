#!/usr/bin/env python
# -*- coding: gbk -*-

###########################
#pandas教程学习
#参考网址：https://www.yiibai.com/pandas/python_pandas_data_structures.html
###########################

import numpy as np
import numpy.matlib
from matplotlib import pyplot as plt
import pandas as pd

def adder(ele1, ele2):
    return ele1 + ele2

dates = pd.date_range("20170101", periods=7)
df = pd.DataFrame(np.random.randn(7, 4) ,index=dates, columns=list('ABCD'))
print df

#pipe() 为什么没有效果
df.pipe(adder,2)
print df

#apply 为什么没有效果
df.apply(np.mean)
print df

#applymap() 为什么没有效果
