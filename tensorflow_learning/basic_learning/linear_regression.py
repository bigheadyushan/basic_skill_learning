#!/usr/bin/python
# -*- coding: gbk -*-


import tensorflow as tf
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

#生成数据
w_real = np.array([[0.1], [0.2]])
b_real = 0.3
x_data = np.float32(np.random.rand(100, 2)) # 2*100
y_data = np.dot(x_data, w_real) + b_real
print y_data.shape
#构建模型
w = tf.Variable(tf.random_uniform([2,1], -1.0, 1.0))
b = tf.Variable(tf.zeros([1]))
y = tf.matmul(x_data, w) + b
#最小化方差
loss = tf.reduce_mean(tf.square(y - y_data))
optimizer = tf.train.GradientDescentOptimizer(0.1)
train = optimizer.minimize(loss)

#初始化变量
init = tf.global_variables_initializer()
#启动图
sess = tf.Session()
sess.run(init)
#拟合
for step in xrange(0, 2000):
    sess.run(train)
    if step % 100 == 0:
        print step, sess.run(w), sess.run(b), sess.run(loss)
sess.close()
