#!/usr/bin/env python
# -*- coding: gbk -*-

###########################
#pandas�̳�ѧϰ
#�ο���ַ��https://www.yiibai.com/pandas/python_pandas_data_structures.html
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

#pipe() Ϊʲôû��Ч��
df.pipe(adder,2)
print df

#apply Ϊʲôû��Ч��
df.apply(np.mean)
print df

#applymap() Ϊʲôû��Ч��
