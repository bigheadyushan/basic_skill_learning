#!/usr/bin/env python
# -*- coding: gbk -*-

###########################
#Numpy��ϸ�̳�ѧϰ
#�ο���ַ��https://blog.csdn.net/a373595475/article/details/79580734
###########################

import numpy as np
import numpy.matlib
from matplotlib import pyplot as plt

###########################
#Numpy ��� 
#�ɶ�ά�������ʹ������ݵ����̼�����ɵĿ�
###########################

###########################
#Numpy ���� 
#�������㣬����Ҷ�任��ͼ�β��������Դ������
###########################

###########################
#Numpy �������
#numpy.array(object, dtype = None, copy = True, order = None, subok = False, ndmin = 0)
###########################
a = np.array([1, 2, 3])
print a
a = np.array([[1, 2], [3, 4]])
print a
a = np.array([[1, 2], [3, 4]], dtype=complex)
print a

###########################
#Numpy ��������,�ṹ������
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
#Numpy ��������
###########################
a = np.array([[1,2,3], [4,5,6]])
print a.shape
#���������С
a.shape = (3,2)
print a
b = a.reshape(3,2)
print b
a =np.arange(24)
print a.ndim
print a.itemsize #ÿ��Ԫ�ص��ֽڵ�λ����
print a.flags #����
b = a.reshape(2,4,3)  
print b

###########################
#Numpy ���鴴������
###########################
a = np.empty([3, 2], dtype=int) #�������(3,2)����Ԫ��Ϊ���ֵ
a = np.empty([3, 2], dtype=int, order= 'C') #�������(3,2)����Ԫ��Ϊ0
a = np.zeros(5)
a = np.zeros(5, dtype=int)
a = np.ones(5)
a = np.ones([2,2])
print a

###########################
#Numpy �����������ݵ�����
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
#Numpy ��Ƭ������,�߼�����
###########################
a = np.arange(10)
s = slice(2,7,2)
print a[s]
print a[2:7:2]
a = np.array([[1,2,3],[3,4,5],[4,5,6]])
print a[..., 1] #�ڶ���
print a[..., 1:] #�ڶ��м��������
print a[1, ...] #�ڶ���
a = np.array([np.nan,  1,2,np.nan,3,4,5]) 
print a[a >  1]
print a[~np.isnan(a)]

###########################
#Numpy �㲥,�������,�㲥����
###########################
a = np.array([[0.0,0.0,0.0],[10.0,10.0,10.0],[20.0,20.0,20.0],[30.0,30.0,30.0]]) 
b = np.array([1.0,2.0,3.0]) 
print a + b
a = np.arange(0,60,5)
a = a.reshape(3,4)  
for x in np.nditer(a):  
    print x,

###########################
#Numpy ���ݲ���
###########################
#�޸���״
#numpy.reshape(arr, newshape, order')
#numpy.flat
#ndarray.flatten(order)
#numpy.ravel

#��ת����
#numpy.transposeת��
#numpy.Tת��
#rollaxis ������ָ������
#swapaxes ���������������

#�޸�ά��
#broadcast ����ģ�¹㲥�Ķ���
#broadcast_to ������㲥������״
#expand_dims ��չ�������״
#squeeze ���������״��ɾ����ά��Ŀ

#��������
#concatenate �����ִ����������������(���ݺϳ�������)
#stack �������������������У����ɰ���������������飩
#hstack ˮƽ�ѵ������е����飨�з���
#vstack ��ֱ�ѵ������е����飨�з���

#����ָ�
#split ��һ������ָ�Ϊ���������
#np.split(a,3)  �������Ϊ������С��ȵ�������
#np.split(a,[4,7]) ��������һά�����б�����λ�÷ָ�
#hsplit ��һ������ˮƽ�ָ�Ϊ��������飨���У�
#vsplit ��һ��������ֱ�ָ�Ϊ��������飨����)

#��Ӻ�ɾ��Ԫ��
#numpy.resize(arr, shape) ����ָ����С��������,����´�С����ԭʼ��С�������ԭʼ�����е�Ԫ�ص��ظ�����
#numpy.append �˺��������������ĩβ���ֵ
#numpy.insert �ظ����������������в���ֵ
#numpy.delete �˺������ش�����������ɾ��ָ���������������
#numpy.unique �����������������е�ȥ��Ԫ������

###########################
#Numpy λ����
###########################
#bitwise_and ������Ԫ��ִ��λ�����
#bitwise_or ������Ԫ��ִ��λ�����
#invert ����λ��
#left_shift �����ƶ������Ʊ�ʾ��λ
#right_shift �����ƶ������Ʊ�ʾ��λ

###########################
#Numpy �ַ�������
###########################
#add() ��������str��Unicode���������ַ�������
#multiply() ���ذ�Ԫ�ض������Ӻ���ַ���
#center() ���ظ����ַ����ĸ���������Ԫ��λ���ض��ַ���������
#capitalize() ���ظ����ַ����ĸ���������ֻ�е�һ���ַ�����д
#title() �����ַ����� Unicode �İ�Ԫ�ر���ת���汾
#lower() ����һ�����飬��Ԫ��ת��ΪСд
#upper() ����һ�����飬��Ԫ��ת��Ϊ��д
#split() �����ַ����еĵ����б���ʹ�÷ָ������ָ�
#splitlines() ����Ԫ���е����б��Ի��з��ָ�
#strip() �������鸱��������Ԫ���Ƴ��˿�ͷ���߽�β�����ض��ַ�
#join() ����һ���ַ����������������ַ���������
#replace() �����ַ����ĸ����������������ַ����ĳ���λ�ö������ַ���ȡ��
#decode() ��Ԫ�ص���str.decode
#encode() ��Ԫ�ص���str.encode

###########################
#Numpy ��������
###########################
#���Ǻ���
#numpy.around() ���뺯��
#numpy.floor()
#numpy.ceil()
#�������� add()��subtract()��multiply()��divide()
#ȡ���� numpy.reciprocal()
#ָ�� numpy.power()
#ȡ�� numpy.mod()

###########################
#Numpy ͳ�ƺ���
###########################
#numpy.amin() �� numpy.amax()
#numpy.ptp()�������������ֵ�ķ�Χ
#numpy.percentile() �ٷ�λ����ͳ����ʹ�õĶ�������ʾС�����ֵ�ù۲�ֵռĳ���ٷֱ�
#numpy.median() ��λ��
#numpy.mean()
#numpy.average()��Ȩƽ��ֵ
#np.std

###########################
#Numpy ���������ͼ�������
###########################
#���� numpy.sort(a, axis, kind, order)
#���򷵻����� numpy.argsort()
#numpy.argmax() �� numpy.argmin()
#numpy.nonzero()�����������������з���Ԫ�ص�����
#where()�������������������������������Ԫ�ص�����
#extract()�������������κ�������Ԫ�ء�

###########################
#Numpy �ֽڽ���,��ͼ��ǳ����
###########################
#numpy.ndarray.byteswap()������������ʾ����˺�С��֮���л�
#NumPy ӵ��ndarray.view()����
#ndarray.copy()��������һ����㸱���� �������鼰�����ݵ���������������ԭʼ���鹲��

###########################
#Numpy �����
###########################
#numpy.matlib����ģ��ĺ������ؾ���
#np.matlib.empty((2,2))
#np.matlib.ones((2,2))
#numpy.matlib.eye(n, M,k, dtype)
#numpy.matlib.identity()�������ظ�����С�ĵ�λ����
#��numpy.matlib.rand()`�������ظ�����С��������ֵ�ľ���

###########################
#Numpy ���Դ���
###########################
#numpy.linalgģ�飬�ṩ���Դ�����������й���
#numpy.dot()������������ĵ��
#numpy.vdot() �������������ĵ��
#numpy.inner() ����һά����������ڻ�
#numpy.matmul()����������������ľ���˻�
#numpy.linalg.det() ����ʽ�����Դ������Ƿǳ����õ�ֵ
#numpy.linalg.solve()���������˾�����ʽ�����Է��̵Ľ�
#numpy.linalg.inv()����������������


