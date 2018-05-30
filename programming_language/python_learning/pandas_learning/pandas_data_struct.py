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

###########################
# pandas Series 
###########################
#ϵ��(Series)���ܹ������κ����͵�����(�������ַ�������������Python�����)��һά������顣���ǩͳ��Ϊ������
#pandas.Series( data, index, dtype, copy)
s = pd.Series([1, 3, 5, np.nan, 6, 8])
print s
s = pd.Series(['h1', 'h2', 'h3'], index=[101,102,103])
print s
dic = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5}
s = pd.Series(dic)
print s

#���ݷ���
print s['a']
print s[0]
print s[['a','b']]
print s[:2]
print s[-3:]

#��������
print s.axes
print s.dtype
print s.empty
print s.ndim
print s.size
print s.values
print s.head()
print s.tail()



###########################
# pandas DataFrame 
###########################
#����֡(DataFrame)�Ƕ�ά���ݽṹ�����������к��еı��ʽ����
#pandas.DataFrame( data, index, columns, dtype, copy)
df = pd.DataFrame([1,3,4])
print df
data = [['a', 10], ['b', 12], ['c', 13]]
df = pd.DataFrame(data, columns=['name', 'age'])
print df

data = [['Alex',10],['Bob',12],['Clarke',13]]
df = pd.DataFrame(data,columns=['Name','Age'],dtype=float)
print df

data = {'Name':['Tom', 'Jack', 'Steve', 'Ricky'],'Age':[28,34,29,42]}
df = pd.DataFrame(data)
print df

data = {'Name':['Tom', 'Jack', 'Steve', 'Ricky'],'Age':[28,34,29,42]}
df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
print df

data = [{'a': 1, 'b': 2},{'a': 5, 'b': 10, 'c': 20}]
df = pd.DataFrame(data)
print df

data = [{'a': 1, 'b': 2},{'a': 5, 'b': 10, 'c': 20}]
df = pd.DataFrame(data, index=['first', 'second'])
print df

data = [{'a': 1, 'b': 2},{'a': 5, 'b': 10, 'c': 20}]

#With two column indices, values same as dictionary keys
df1 = pd.DataFrame(data, index=['first', 'second'], columns=['a', 'b'])

#With two column indices with one index with other name
df2 = pd.DataFrame(data, index=['first', 'second'], columns=['a', 'b1'])
print df1
print df2


d = {'one' : pd.Series([1, 2, 3], index=['a', 'b', 'c']),
      'two' : pd.Series([1, 2, 3, 4], index=['a', 'b', 'c', 'd'])}
df = pd.DataFrame(d)
print df
#��ѡ��
print df['one']
#�����
df['three']=pd.Series([10,20,30],index=['a','b','c'])
#��ɾ��
del df['one']
df.pop('two')

d = {'one' : pd.Series([1, 2, 3], index=['a', 'b', 'c']),
      'two' : pd.Series([1, 2, 3, 4], index=['a', 'b', 'c', 'd'])}
df = pd.DataFrame(d)
print df
#��ѡ��
print df.loc[1:2]
print df.loc['a']
print df.iloc[2]
#�����
#df = df.append(df2)
#��ɾ��
# Drop rows with label 0
#df = df.drop(0)

#��������
print pd.T
print pd.axes
print pd.dtype
print pd.empty
print pd.ndim
print pd.shape
print pd.size
print pd.values
print pd.head()
print pd.tail()

#������ͳ��
#df.sum()
#df.mean()
#df.std()
#count()
#median()
#mode()
#min()
#max()
#abs()
#prod
#cumsum
#cumprod
#decrible()

###########################
# pandas Panel 
###########################
#���(Panel)��3D����������
#pandas.Panel(data, items, major_axis, minor_axis, dtype, copy|112 #���(Panel)��3D����������)
