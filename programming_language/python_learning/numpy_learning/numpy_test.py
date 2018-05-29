#!/usr/bin/env python
# -*- coding: gbk -*-

###########################
#Numpy详细教程学习
#参考网址：https://blog.csdn.net/a373595475/article/details/79580734
###########################

import numpy as np
import numpy.matlib
from matplotlib import pyplot as plt

###########################
#Numpy 简介 
#由多维数组对象和处理数据的例程集合组成的库
###########################

###########################
#Numpy 操作 
#数组运算，傅立叶变换，图形操作，线性代数相关
###########################

###########################
#Numpy 数组对象
#numpy.array(object, dtype = None, copy = True, order = None, subok = False, ndmin = 0)
###########################
a = np.array([1, 2, 3])
print a
a = np.array([[1, 2], [3, 4]])
print a
a = np.array([[1, 2], [3, 4]], dtype=complex)
print a

###########################
#Numpy 数据类型,结构化类型
###########################
dt = np.dtype(np.int32)
print dt
dt = np.dtype([("age", np.int8)])
a = np.array([(10, ), (20, ), (40, )], dtype=dt)
print a
print a['age']
student = np.dtype([('name', 'S20'), ('age', 'i1'), ('marks', 'f4')])
print student
a = np.array([('abc',  21,  50),('xyz',  18,  75)], dtype = student)
print a

###########################
#Numpy 数组属性
###########################
a = np.array([[1,2,3], [4,5,6]])
print a.shape
#调整数组大小
a.shape = (3,2)
print a
b = a.reshape(3,2)
print b
a =np.arange(24)
print a.ndim
print a.itemsize #每次元素的字节单位长度
print a.flags #属性
b = a.reshape(2,4,3)  
print b

###########################
#Numpy 数组创建例程
###########################
a = np.empty([3, 2], dtype=int) #随机生成(3,2)矩阵，元素为随机值
a = np.empty([3, 2], dtype=int, order= 'C') #随机生成(3,2)矩阵，元素为0
a = np.zeros(5)
a = np.zeros(5, dtype=int)
a = np.ones(5)
a = np.ones([2,2])
print a

###########################
#Numpy 来自现有数据的数组
###########################
#numpy.asarray(a, dtype = None, order = None)
x = [1,2,3]
a = np.asarray(x)
a = np.asarray(x, dtype=float)
x =  (1,2,3)
a = np.asarray(x)
x =  [(1,2,3),(4,5)] 
a = np.asarray(x)
#numpy.frombuffer(buffer, dtype = float, count = -1, offset = 0)
s =  'Hello World' 
a = np.frombuffer(s, dtype =  'S1')
#numpy.fromiter(iterable, dtype, count = -1)
alist = range(5)
a = np.fromiter(alist, dtype =  float)
print a
x = np.fromiter(iter(alist), dtype =  float)
print a
#numpy.linspace(start, stop, num, endpoint, retstep, dtype)
#numpy.logscale(start, stop, num, endpoint, base, dtype)

###########################
#Numpy 切片和索引,高级索引
###########################
a = np.arange(10)
s = slice(2,7,2)
print a[s]
print a[2:7:2]
a = np.array([[1,2,3],[3,4,5],[4,5,6]])
print a[..., 1] #第二列
print a[..., 1:] #第二列及其后面列
print a[1, ...] #第二行
a = np.array([np.nan,  1,2,np.nan,3,4,5]) 
print a[a >  1]
print a[~np.isnan(a)]

###########################
#Numpy 广播,数组迭代,广播迭代
###########################
a = np.array([[0.0,0.0,0.0],[10.0,10.0,10.0],[20.0,20.0,20.0],[30.0,30.0,30.0]]) 
b = np.array([1.0,2.0,3.0]) 
print a + b
a = np.arange(0,60,5)
a = a.reshape(3,4)  
for x in np.nditer(a):  
    print x,

###########################
#Numpy 数据操作
###########################
#修改形状
#numpy.reshape(arr, newshape, order')
#numpy.flat
#ndarray.flatten(order)
#numpy.ravel

#翻转操作
#numpy.transpose转置
#numpy.T转置
#rollaxis 向后滚动指定的轴
#swapaxes 互换数组的两个轴

#修改维度
#broadcast 产生模仿广播的对象
#broadcast_to 将数组广播到新形状
#expand_dims 扩展数组的形状
#squeeze 从数组的形状中删除单维条目

#数组连接
#concatenate 沿着现存的轴连接数据序列(数据合成新数组)
#stack 沿着新轴连接数组序列（生成包含两个数组的数组）
#hstack 水平堆叠序列中的数组（列方向）
#vstack 竖直堆叠序列中的数组（行方向）

#数组分隔
#split 将一个数组分割为多个子数组
#np.split(a,3)  将数组分为三个大小相等的子数组
#np.split(a,[4,7]) 将数组在一维数组中表明的位置分割
#hsplit 将一个数组水平分割为多个子数组（按列）
#vsplit 将一个数组竖直分割为多个子数组（按行)

#添加和删除元素
#numpy.resize(arr, shape) 返回指定大小的新数组,如果新大小大于原始大小，则包含原始数组中的元素的重复副本
#numpy.append 此函数在输入数组的末尾添加值
#numpy.insert 沿给定轴在输入数组中插入值
#numpy.delete 此函数返回从输入数组中删除指定子数组的新数组
#numpy.unique 函数返回输入数组中的去重元素数组

###########################
#Numpy 位操作
###########################
#bitwise_and 对数组元素执行位与操作
#bitwise_or 对数组元素执行位或操作
#invert 计算位非
#left_shift 向左移动二进制表示的位
#right_shift 向右移动二进制表示的位

###########################
#Numpy 字符串函数
###########################
#add() 返回两个str或Unicode数组的逐个字符串连接
#multiply() 返回按元素多重连接后的字符串
#center() 返回给定字符串的副本，其中元素位于特定字符串的中央
#capitalize() 返回给定字符串的副本，其中只有第一个字符串大写
#title() 返回字符串或 Unicode 的按元素标题转换版本
#lower() 返回一个数组，其元素转换为小写
#upper() 返回一个数组，其元素转换为大写
#split() 返回字符串中的单词列表，并使用分隔符来分割
#splitlines() 返回元素中的行列表，以换行符分割
#strip() 返回数组副本，其中元素移除了开头或者结尾处的特定字符
#join() 返回一个字符串，它是序列中字符串的连接
#replace() 返回字符串的副本，其中所有子字符串的出现位置都被新字符串取代
#decode() 按元素调用str.decode
#encode() 按元素调用str.encode

###########################
#Numpy 算数函数
###########################
#三角函数
#numpy.around() 舍入函数
#numpy.floor()
#numpy.ceil()
#算数运算 add()，subtract()，multiply()和divide()
#取倒数 numpy.reciprocal()
#指数 numpy.power()
#取余 numpy.mod()

###########################
#Numpy 统计函数
###########################
#numpy.amin() 和 numpy.amax()
#numpy.ptp()函数返回沿轴的值的范围
#numpy.percentile() 百分位数是统计中使用的度量，表示小于这个值得观察值占某个百分比
#numpy.median() 中位数
#numpy.mean()
#numpy.average()加权平均值
#np.std

###########################
#Numpy 排序、搜索和计数函数
###########################
#排序 numpy.sort(a, axis, kind, order)
#排序返回索引 numpy.argsort()
#numpy.argmax() 和 numpy.argmin()
#numpy.nonzero()函数返回输入数组中非零元素的索引
#where()函数返回输入数组中满足给定条件的元素的索引
#extract()函数返回满足任何条件的元素。

###########################
#Numpy 字节交换,视图或浅复制
###########################
#numpy.ndarray.byteswap()函数在两个表示：大端和小端之间切换
#NumPy 拥有ndarray.view()方法
#ndarray.copy()函数创建一个深层副本。 它是数组及其数据的完整副本，不与原始数组共享

###########################
#Numpy 矩阵库
###########################
#numpy.matlib。此模块的函数返回矩阵
#np.matlib.empty((2,2))
#np.matlib.ones((2,2))
#numpy.matlib.eye(n, M,k, dtype)
#numpy.matlib.identity()函数返回给定大小的单位矩阵
#·numpy.matlib.rand()`函数返回给定大小的填充随机值的矩阵

###########################
#Numpy 线性代数
###########################
#numpy.linalg模块，提供线性代数所需的所有功能
#numpy.dot()返回两个数组的点积
#numpy.vdot() 返回两个向量的点积
#numpy.inner() 返回一维数组的向量内积
#numpy.matmul()函数返回两个数组的矩阵乘积
#numpy.linalg.det() 行列式在线性代数中是非常有用的值
#numpy.linalg.solve()函数给出了矩阵形式的线性方程的解
#numpy.linalg.inv()函数来计算矩阵的逆


