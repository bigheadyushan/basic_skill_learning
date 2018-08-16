#!/usr/bin/python
# -*- coding: gbk -*-


import tensorflow as tf
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

#��������
w_real = np.array([[0.1], [0.2]])
b_real = 0.3
x_data = np.float32(np.random.rand(100, 2)) # 2*100
y_data = np.dot(x_data, w_real) + b_real
#����ģ��
x_ph = tf.placeholder(tf.float32, shape=[None, 2], name="input_name")
y_ph = tf.placeholder(tf.float32, shape=[None, 1], name="output_name")
w = tf.Variable(tf.random_uniform([2,1], -1.0, 1.0))
b = tf.Variable(tf.zeros([1]))
y = tf.matmul(x_ph, w) + b
#��С������
loss = tf.reduce_mean(tf.square(y - y_ph))
optimizer = tf.train.GradientDescentOptimizer(0.1)
train = optimizer.minimize(loss)

#��ʼ������
init = tf.global_variables_initializer()
#����ͼ
sess = tf.Session()
sess.run(init)
#���
for step in xrange(0, 200):
    total_loss = 0.0
    for i in range(len(x_data)):
        feed_data = {x_ph: [x_data[i]], y_ph: [y_data[i]]}
        print feed_data
        sess.run(train, feed_dict = feed_data)
        total_loss += sess.run(loss, feed_data)
    if step % 10 == 0:
        print step, sess.run(w), sess.run(b), total_loss
sess.close()
