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

print "hello, Pandas"

s = pd.Series([1, 3, 5, np.nan, 6, 8])
print s

dates = pd.date_range("20170101", periods=7)
print dates

print "--" * 16
df = pd.DataFrame(np.random.randn(7, 4) ,index=dates, columns=list('ABCD'))
print df

tmp_dic = {'A': 1.0, \
           'B': pd.Timestamp('20180530'),\
           'C': pd.Series(1, index=list(range(4)), dtype='float32'),
           'D': np.array([3] * 4, dtype='int32'),
           'E': pd.Categorical(['test', 'train', 'test', 'train']),           
           'F': 'foo'}
df = pd.DataFrame(tmp_dic)
print df
print "--" * 16
df = pd.DataFrame(np.random.randn(7, 4) ,index=dates, columns=list('ABCD'))
print df.head(1)
print "--" * 16
print df.tail(3)
print "--" * 16
print df.index
print df.columns
print df.values
print df.describe()
print df.T
print df.sort_index(axis=1, ascending=False)
print df.sort_values(by='B')
print "--" * 16
print df

print df['A']
print df[0:3] #前三行
print df['20170101':'20170103'] #前三行
#根据index值确定
print df.loc[dates[0]] #根据index获取一行数据
print df.loc[:,['A','B']]
print df.loc['20170101':'20170103', ['A','B']]
print df.loc[dates[0],'A']
print df.at[dates[0],'A'] #等同与df.loc[dates[0],'A']
#根据位置确定
print df.iloc[3]
print df.iloc[3:5, 0:2]
print df.iloc[[1,2,4], [0,2]]
print df.iloc[:,1:3]
print df.iloc[1,1] 
print df.iat[1,1] #等同于df.iloc[1,1]
#布尔索引
print "--" * 16
print df
print df[df.A > 0]
print df[df > 0]
df2 = df.copy()
df2['E'] = ['three', 'one', 'two', 'three', 'four','one', 'two']
print df2
print df2[df2['E'].isin(['one','two'])]










